// Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/
// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//
//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
//
//Notice that you should not modify the linked list.
//
//Follow up:
//
//Can you solve it using O(1) (i.e. constant) memory?

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
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head or !head->next or !head->next->next)
            return nullptr;
        ListNode *slow = head, *fast = head;
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while(slow != head){
                    slow = slow->next;
                    head = head->next;
                }
                return head;
            }
        }
        return nullptr;
    }
};