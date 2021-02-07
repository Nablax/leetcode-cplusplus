// 1673. Find the Most Competitive Subsequence
//Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.
//
//An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.
//
//We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.
//
// https://leetcode.com/problems/find-the-most-competitive-subsequence/
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
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        if(nums.size() == k) return nums;
        std::vector<int> res;
        res.reserve(k + 1);
        for(int i = 0; i < nums.size(); i++){
            // use a stack to keep the min nums
            while(!res.empty() and nums[i] < res.back() and nums.size() - i + res.size() > k){
                res.pop_back();
            }
            if(res.size() < k) res.push_back(nums[i]);
        }
        return res;
    }
};