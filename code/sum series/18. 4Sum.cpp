// 18. 4Sum
//
// https://leetcode.com/problems/4sum/
// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target?
// Find all unique quadruplets in the array which gives the sum of target.
//
// using iterative ideas to find the N sum results, very cool

#include <queue>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <iostream>

class Solution {
public:
    void findSum(std::vector<int> &tmpNums, std::vector<int> &nums, int n, int left, int right, int target){
        if(n == 2){
            int tmp;
            while(left < right){
                tmp = nums[left] + nums[right];
                if(target == tmp){
                    tmpNums[N - 2] = nums[left];
                    tmpNums[N - 1] = nums[right];
                    res.push_back(tmpNums);
                    while(left < right and nums[left] == nums[left + 1]) left++;
                    while(left < right and nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
                else if(target < tmp) right--;
                else left++;
            }
            return;
        }
        for(int i = left; i <= right - n + 1; i++){
            if(i > left and nums[i] == nums[i - 1])
                continue;
            tmpNums[N - n] = nums[i];
            findSum(tmpNums, nums, n - 1, i + 1, right, target - nums[i]);
        }
    }

    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        int numsLen = nums.size();
        N = 4;
        std::sort(nums.begin(), nums.end());
        if(numsLen < N || nums[0] * N > target || nums[numsLen - 1] * N < target)
            return {};
        std::vector<int> tmpRes(N, 0);
        findSum(tmpRes, nums, N, 0, numsLen - 1, target);
        return res;
    }

private:
    std::vector<std::vector<int>> res;
    int N;
};

int main(){
    std::vector<int> nums = {1,-1,-1,0};
    Solution c;
}