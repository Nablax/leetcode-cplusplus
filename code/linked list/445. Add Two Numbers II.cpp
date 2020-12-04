// 445. Add Two Numbers II
// https://leetcode.com/problems/add-two-numbers-ii/
//You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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
    ListNode() : val(), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    int getLength(ListNode *cur){
        if(!cur)
            return 0;
        int res = 1;
        while(cur->next && cur->next->next){
            cur = cur->next->next;
            res += 2;
        }
        if(cur->next){
            res += 1;
        }
        return res;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        int l1Len = getLength(l1);
        int l2Len = getLength(l2);
        std::vector<int> tmp(std::max(l1Len, l2Len), 0);
        auto curl1 = l1, curl2 = l2;
        for(int i = 0; i < tmp.size(); i++){
            if(i >= tmp.size() - l1Len){
                tmp[i] += curl1->val;
                curl1 = curl1->next;
            }
            if(i >= tmp.size() - l2Len){
                tmp[i] += curl2->val;
                curl2 = curl2->next;
            }
        }
        int bit = 0;
        auto head = new ListNode();
        ListNode *cur = nullptr;
        for(auto x = tmp.rbegin(); x != tmp.rend(); x++){
            int curNode = *x;
            curNode += bit;
            bit = 0;
            if(curNode >= 10){
                curNode %= 10;
                bit = 1;
            }
            if(head->next) cur = head->next;
            head->next = new ListNode(curNode, cur);
        }
        if(bit) head->val = 1;
        else head = head->next;
        return head;
    }
};

int main(){
    Solution c;
    ListNode *l1, *l2;
    //std::vector<int> t = {3, 1, 2};
    //std::vector<int> t = {2, 2, 2, 2, 2};
    //std::cout << c.findNumberOfLIS(t);
}