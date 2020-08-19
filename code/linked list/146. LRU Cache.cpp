//146. LRU Cache
//
//https://leetcode.com/problems/lru-cache/
//link node need a lonely head and tail.

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
        head = new linkNode(0, 0);
        tail = new linkNode(0, 0);
        head->bef = head->next = tail;
        tail->bef = tail->next = head;
        dic.clear();
    }

    void removeNode(linkNode *tmp){
        tmp->bef->next = tmp->next;
        tmp->next->bef = tmp->bef;
        delete tmp;
    }

    void pushback(int key, linkNode *tmp){
        auto cur = tail->bef;
        tmp->next = tail;
        tail->bef = tmp;
        cur->next = tmp;
        tmp->bef = cur;
        dic[key] = tmp;
    }

    int get(int key) {
        auto it = dic.find(key);
        if(it == dic.end())
            return -1;
        auto value = it->second->value;
        removeNode(it->second);
        pushback(key, new linkNode(key, value));
        return value;
    }

    void put(int key, int value) {
        int fsize = dic.size();
        auto it = dic.find(key);
        if(it != dic.end()){
            removeNode(it->second);
        }
        else if(fsize == cap){
            dic.erase(head->next->key);
            removeNode(head->next);
        }
        pushback(key, new linkNode(key, value));
    }
private:
    std::unordered_map<int, linkNode*> dic;
    int cap;
    linkNode *head;
    linkNode *tail;
};