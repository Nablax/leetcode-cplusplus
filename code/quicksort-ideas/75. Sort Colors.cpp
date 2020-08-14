// https://leetcode.com/problems/sort-colors/submissions/
// Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
# include <vector>
class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        for(int i = 0; i < nums.size(); ){
            if(nums[i] == 0 and i > left)
                std::swap(nums[i], nums[left++]);
            else if(nums[i] == 2 and i < right)
                std::swap(nums[i], nums[right--]);
            else
                i++;
        }
    }
};