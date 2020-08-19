//460. LFU Cache
//
//https://leetcode.com/problems/lfu-cache/
//link node need a lonely head and tail. store multiple nodes by accessed time.

#include <queue>
#include <algorithm>
#include <unordered_map>
#include <map>

class linkNode{
public:
    linkNode(int k, int v, int t = 0):key(k), value(v), times(t){}
    int key, value, times = 0;
    linkNode *bef;
    linkNode *next;
};

class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
        dic.clear();
    }

    void removeNode(linkNode *tmp){
        if(tmp->bef->bef == tmp->next){
            dic_times.erase(tmp->times);
            delete tmp->bef;
            delete tmp->next;
            delete tmp;
            return;
        }
        tmp->bef->next = tmp->next;
        tmp->next->bef = tmp->bef;
        delete tmp;
    }

    void pushNode(linkNode *tmp){
        auto key = tmp->key;
        auto times = tmp->times;
        if(dic_times.find(times) == dic_times.end()){
            auto head = new linkNode(0, 0);
            auto tail = new linkNode(0, 0);
            head->bef = head->next = tail;
            tail->bef = tail->next = head;
            dic_times[times] = std::make_pair(head, tail);
        }
        auto tail = dic_times[times].second;
        auto cur = tail->bef;
        tmp->next = tail;
        tail->bef = tmp;
        cur->next = tmp;
        tmp->bef = cur;
        dic[key] = tmp;
    }

    int get(int key) {
        if(cap == 0)
            return -1;
        auto it = dic.find(key);
        if(it == dic.end())
            return -1;
        auto value = it->second->value;
        auto times = it->second->times  + 1;
        removeNode(it->second);
        pushNode(new linkNode(key, value, times));
        return value;
    }

    void put(int key, int value) {
        if(cap == 0)
            return;
        int fsize = dic.size();
        auto it = dic.find(key);
        if(it != dic.end()){
            auto tmpNode = new linkNode(key, value, it->second->times + 1);
            removeNode(it->second);
            pushNode(tmpNode);
            return;
        }
        if(fsize == cap){
            auto remove_at = dic_times.begin()->second.first->next;
            dic.erase(remove_at->key);
            removeNode(remove_at);
        }
        pushNode(new linkNode(key, value));
    }
private:
    std::unordered_map<int, linkNode*> dic;
    std::map<int, std::pair<linkNode*, linkNode *>> dic_times;
    int cap;
};

int main(){
    LFUCache *cache = new LFUCache( 3 /* capacity */ );
    int a;
    cache->put(1, 1);
    cache->put(2, 2);    // evicts key 2
    cache->put(3, 3);
    a = cache->get(1);       // returns -1 (not found)
    a = cache->get(1);
    a = cache->get(2);       // returns -1 (not found)
    a = cache->get(3); // evicts key 1
    cache->put(1, 4);
    cache->put(4, 1);
    a = cache->get(2);       // returns 4
}

//int main(){
//    LFUCache *cache = new LFUCache( 3 /* capacity */ );
//    int a;
//    cache->put(1, 1);
//    cache->put(2, 2);    // evicts key 2
//    cache->put(3, 3);
//    a = cache->get(1);       // returns -1 (not found)
//    a = cache->get(1);
//    a = cache->get(2);       // returns -1 (not found)
//    a = cache->get(3); // evicts key 1
//    cache->put(1, 4);
//    cache->put(4, 1);
//    a = cache->get(2);       // returns 4
//}