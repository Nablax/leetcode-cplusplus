// 23. Merge k Sorted Lists
//You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//
//Merge all the linked-lists into one sorted linked-list and return it.

// https://leetcode.com/problems/merge-k-sorted-lists/
#include <algorithm>
#include <unordered_map>
#include <map>
#include <iostream>
#include <cmath>
#include <set>
#include <list>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <bitset>
#include <memory>
#include <numeric>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// lambda表达式和优先队列的应用
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        auto head = new ListNode();
        ListNode *cur = head, *tmp;
        auto cmp = [](ListNode* n1, ListNode* n2){return n1->val > n2->val;};
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> q(cmp);
        for(auto &list: lists){
            if(list) q.push(list);
        }
        while(!q.empty()){
            tmp = q.top();
            q.pop();
            cur->next = tmp;
            cur = cur->next;
            if(tmp->next) q.push(tmp->next);
        }
        return head->next;
    }
};