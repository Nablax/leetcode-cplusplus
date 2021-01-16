// 1658. Minimum Operations to Reduce X to Zero
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
// You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.
//
//Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.

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

//this question makes me know it inefficient to check the map all the time
//找中间最大的数组而不是找两端，也可以双指针，此时双指针并不是从两侧而是同侧
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        nums.insert(nums.begin(), 0);
        for (int i=1;i<nums.size();++i) nums[i] += nums[i-1];

        int best = -1;
        int target = nums.back() - x;
        int head = 0;
        for (int i=1;i<nums.size();++i) {
            while(head < nums.size() && nums[i] - nums[head] > target) ++head;
            if (nums[i]-nums[head] == target) {
                best = max(best, i - head);
            }
        }
        if (best < 0) return best;
        return nums.size()-best-1;
    }
};

class Solution1_1 {
public:
    int minOperations(vector<int>& nums, int x) {
        int res = nums.size() + 1, n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(i > 0) nums[i] += nums[i - 1];
            if(nums[i] == x) res = i + 1;
        }
        int tofind = nums.back() - x;
        if(tofind < 0) return -1;
        std::unordered_map<int, int> um;
        um[tofind] = -1;
        for(int i = 0; i < nums.size(); i++){
            if(tofind + nums[i] < nums.back())
                um[tofind + nums[i]] = i;
            if(um.find(nums[i]) != um.end()){
                res = std::min(res, n - i + um[nums[i]]);
            }
        }
        return res > n? -1: res;
    }
};

//双指针，有点有趣
class Solution2{
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = std::accumulate(begin(nums), end(nums), 0);
        int l = 0, r = 0, res = INT_MAX, sz = nums.size();
        while (l <= r)
            if (sum >= x) {
                if (sum == x)
                    res = min(res, l + sz - r);
                if (r < sz)
                    sum -= nums[r++];
                else
                    break;
            }
            else
                sum += nums[l++];
        return res == INT_MAX ? -1 : res;
    }
};

class Solution3 {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> leftSumMap, rightSumMap;
        int leftSum = 0, rightSum = 0;
        int minNum = 999999;
        for(int i = 0; i < nums.size(); i++){
            leftSum += nums[i];
            rightSum += nums[nums.size() - 1 - i];
            if(leftSum > x and rightSum > x)
                break;
            if(leftSum == x){
                minNum = min(minNum, i + 1);
            }
            if(rightSum == x){
                minNum = min(minNum, i + 1);
            }
            if(leftSum < x) leftSumMap[leftSum] = i + 1;
            if(rightSum < x) rightSumMap[rightSum] = i + 1;
        }
        int left, right;
        for(auto it = leftSumMap.begin(); it!=leftSumMap.end(); it++){
            if(rightSumMap.find(x - it->first)!=rightSumMap.end()){
                left = it->second;
                right = rightSumMap[x - it->first];
                if(left + right > nums.size()) break;
                minNum = min(minNum, left + right);
            }
        }
        if(minNum == 999999)
            minNum = -1;
        return minNum;
    }
};