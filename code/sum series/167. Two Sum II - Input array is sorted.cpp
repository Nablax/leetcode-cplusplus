//167. Two Sum II - Input array is sorted
//
//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
//If is sorted, find the value from behind and front

#include <queue>
#include <algorithm>
#include <unordered_map>
#include <map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int tmp;
        while(left < right){
            tmp = nums[left] + nums[right];
            if(tmp == target)
                return {++left, ++right};
            else if(tmp > target)
                right--;
            else
                left++;
        }
        return {};
    }
};