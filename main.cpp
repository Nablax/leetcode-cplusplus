//49. Group Anagrams
//
//https://leetcode.com/problems/group-anagrams/
//Given an array of strings, group anagrams together.

#include <queue>
#include <algorithm>
#include <unordered_map>

class linkNode{
public:
    linkNode(int k, int v):key(k), value(v){}
    int key, value;
    linkNode *bef;
    linkNode *next;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        tail = head = new linkNode(0, 0);
        head->bef = head->next = tail;
        dic.clear();
    }

    void remove(linkNode *tmp){
        dic.erase(tmp->value);
        if(tmp == tail and tmp == head){
            return;
        }
        if(tmp == tail){
            head->next = head->bef = tail = head;
            return;
        }

        if(tmp == head){
            tail->next = tail->bef = head = tail;
            return;
        }
        tmp->bef->next = tmp->next;
        tmp->next->bef = tmp->bef;
    }

    void removeHead(){
        dic.erase(head->key);
        if(head != tail){
            auto tmp = head;
            head = head->next;
            head->bef = tail;
            tail->next = head;
            delete tmp;
        }
    }

    void pushback(int key, linkNode *tmp){
        if(dic.empty()){
            head->key = tmp->key;
            head->value = tmp->value;
            dic[key] = head;
            return;
        }
        tmp->next = head;
        tmp->bef = tail->bef;
        tail->next = tmp;
        head->bef = tmp;
        tail = tmp;
        dic[key] = tmp;
    }

    int get(int key) {
        auto it = dic.find(key);
        if(it == dic.end())
            return -1;
        auto res = it->second;
        auto tmp = res->value;
        remove(res);
        pushback(key, res);
        return tmp;
    }


    void put(int key, int value) {
        int fsize = dic.size();
        auto it = dic.find(key);
        if(it != dic.end()){
            auto tmp = it->second;
            tmp->value = value;
            remove(tmp);
            pushback(key, tmp);
        }
        else{
            if(fsize == cap){
                removeHead();
            }
            pushback(key, new linkNode(key, value));
        }
    }
private:
    std::unordered_map<int, linkNode*> dic;
    int cap;
    linkNode *head;
    linkNode *tail;
};

int main(){
    LRUCache *cache = new LRUCache( 1 /* capacity */ );

    cache->put(2, 1);
    int a = cache->get(2);       // returns 1
    cache->put(3, 2);    // evicts key 2
    a = cache->get(2);       // returns -1 (not found)
    cache->put(4, 4);    // evicts key 1
    cache->get(1);       // returns -1 (not found)
    cache->get(3);       // returns 3
    cache->get(4);       // returns 4

}