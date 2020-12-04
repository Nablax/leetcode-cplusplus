// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
// prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

// https://leetcode.com/problems/find-the-duplicate-number/

#include <vector>
class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int start = 1, end = nums.size();
        while(start < end){
            int mid = start + (end - start) / 2;
            int numLess = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] <= mid){
                    numLess++;
                }
            }
            if(numLess > mid){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        return start;
    }
};