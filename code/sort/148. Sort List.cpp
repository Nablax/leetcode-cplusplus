// 148. Sort List
//
// https://leetcode.com/problems/sort-list/
// Given the head of a linked list, return the list after sorting it in ascending order.
//
//Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

// merge sort idea

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
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode *merge(ListNode *l, ListNode *r){
        ListNode *resNode = new ListNode(0), *tmp, *head;
        head = resNode;
        while(l and r){
            if(l->val < r->val){
                resNode->next = l;
                l = l->next;
            }
            else{
                resNode->next = r;
                r = r->next;
            }
            resNode = resNode->next;
        }
        if(l)
            resNode->next = l;
        if(r)
            resNode->next = r;
        tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode *slow = head, *fast = head->next->next;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *r = sortList(slow->next);
        slow->next = nullptr;
        ListNode *l = sortList(head);
        return merge(l, r);
    }
};