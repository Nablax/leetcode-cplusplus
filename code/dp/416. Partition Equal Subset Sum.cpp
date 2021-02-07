// 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/
// Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

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
    bool canPartition(vector<int>& nums) {
        int _sum = 0, _max = INT_MIN;
        for(int num: nums){
            _sum += num;
            if(num > _max) _max = num;
        }
        if (_sum & 1 || _max > _sum / 2) return false;
        _sum /= 2;
        if(_max == _sum) return true;
        std::vector<bool> dp(_sum + 1, false);
        dp[0] = true;
        for (int num : nums) {
            if(num == _sum or dp[_sum]) return true;
            for (int j = _sum; j >= num; --j)
                if(dp[j - num]) dp[j] = true;
        }
        return dp[_sum];
    }
};