//15. 3Sum
//
//https://leetcode.com/problems/3sum/
//Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
//Find all unique triplets in the array which gives the sum of zero.
//
//Get one, and find two sum of the rest

#include <queue>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <iostream>

class Solution {
public:

    void twoSum(std::vector<int> &tmpNums,std::vector<int> &nums, int left, int right, int target){
        for(auto x: tmpNums){
            target -= x;
        }
        tmpNums.push_back(0);
        tmpNums.push_back(0);
        int tmpLen = tmpNums.size();
        while(left < right){
            if(target == nums[left] + nums[right]){
                tmpNums[tmpLen - 2] = nums[left];
                tmpNums[tmpLen - 1] = nums[right];
                res.push_back(tmpNums);
                while(left < right and nums[left] == nums[left + 1]) left++;
                while(left < right and nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            }
            else if(target < nums[left] + nums[right]) right--;
            else left++;
        }
    }

    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        if(nums.size() < 3)
            return {};
        std::sort(nums.begin(), nums.end());
        std::vector<int> tmp;
        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 and nums[i - 1] == nums[i])
                continue;
            tmp.clear();
            tmp.push_back(nums[i]);
            twoSum(tmp,nums,i + 1,nums.size() - 1,0);
        }
        return res;
    }

private:
    std::vector<std::vector<int>> res;
};

int main(){
    std::vector<int> nums = {1,-1,-1,0};
    Solution c;
    c.threeSum(nums);
}