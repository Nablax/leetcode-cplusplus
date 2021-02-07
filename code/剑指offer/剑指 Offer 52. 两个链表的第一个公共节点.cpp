//剑指 Offer 52. 两个链表的第一个公共节点
//输入两个链表，找出它们的第一个公共节点。

// https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/

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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA or !headB) return nullptr;
        auto curA = headA, curB = headB;
        int countA = 1, countB = 1;
        while(curA->next){
            curA = curA->next;
            countA++;
        }
        while(curB->next){
            curB = curB->next;
            countB++;
        }
        if(curA != curB) return nullptr;
        int diff = std::abs(countA - countB);
        auto &tmp = countA > countB? headA: headB;
        while(diff--) tmp = tmp->next;
        while(headA and headB){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};


//思路很妙，当一个链表走到头转到另一个链表去，这样他们俩总会在末尾或者中间某个地方相遇。
class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto curA = headA, curB = headB;
        while(curA != curB){
            curA = curA == nullptr? headB: curA->next;
            curB = curB == nullptr? headA: curB->next;
        }
        return curA;
    }
};