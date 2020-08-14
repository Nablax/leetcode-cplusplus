#include <vector>
using namespace std;
//Design a HashSet without using any built-in hash table libraries.
//
//To be specific, your design should include these functions:
//
//add(value): Insert a value into the HashSet.
//contains(value) : Return whether the value exists in the HashSet or not.
//remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        vecLen = 0;
    }

    void add(int key) {
        if(vecLen == 0){
            hashMap.push_back(key);
            vecLen++;
            return;
        }
        int idx = findkey(key, 0, vecLen - 1);
        if(hashMap[idx] != key){
            idx += hashMap[idx] < key;
            hashMap.insert(hashMap.begin() + idx, key);
            vecLen++;
        }
    }

    void remove(int key) {
        if(vecLen == 0){
            return;
        }
        int idx = findkey(key, 0, vecLen - 1);
        if(hashMap[idx] == key){
            hashMap.erase(hashMap.begin() + idx);
            vecLen--;
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(vecLen == 0){
            return false;
        }
        int b = hashMap[0];
        return hashMap[findkey(key, 0, vecLen - 1)] == key;
    }

private:
    vector<int> hashMap;
    int findkey(int key, int left, int right){
        if(key <= hashMap[left]){
            return left;
        }
        else if(key >= hashMap[right]){
            return right;
        }
        while(true){
            int half = (left + right) / 2;
            if(key == hashMap[half]){
                return half;
            }
            if(key > hashMap[half]){
                left = half;
            }
            else{
                right = half;
            }
            if(left == right or right - left == 1){
                return left;
            }
        }
    }
    int vecLen;
};

class MyHashSet1 {
public:
    /** Initialize your data structure here. */
    MyHashSet1() {
        hashMap.resize(1000001, false);
    }

    void add(int key) {
        hashMap[key] = true;
    }

    void remove(int key) {
        hashMap[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hashMap[key];
    }

private:
    vector<bool> hashMap;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */