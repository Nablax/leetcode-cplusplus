// 169. Majority Element
//Given an array nums of size n, return the majority element.
//
//The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

//https://leetcode.com/problems/majority-element/
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


class Solution {
public:
    //简言之，整了一个投票系统，两个不同的数字相互抵消，如果某个数字超过一半总会剩下，moore's voting algo
   int majorityElement(vector<int>& nums) {
        int count = 0, cur = 0;
        for(auto &x: nums){
            if(count == 0) cur = x;
            if(x == cur) count++;
            else count--;
        }
        return cur;
    }
};