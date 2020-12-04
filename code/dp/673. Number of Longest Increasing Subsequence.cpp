// 673. Number of Longest Increasing Subsequence
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/
// Given an integer array nums, return the number of longest increasing subsequences.

// The dp solution is to record the longest Increasing Subsequence that end with nums[k]

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
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int numSize = nums.size();
        if(numSize < 2){
            return numSize;
        }
        std::vector<int> maxSize(numSize, 1), maxSizeCount(numSize, 1);
        int retMaxSize = -1, ret = 0;
        for(int i = 0; i < numSize; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(maxSize[i] < maxSize[j] + 1){
                        maxSize[i] = maxSize[j] + 1;
                        maxSizeCount[i] = maxSizeCount[j];
                    }
                    else if(maxSize[i] == maxSize[j] + 1){
                        maxSizeCount[i] += maxSizeCount[j];
                    }
                }
            }
            if(maxSize[i] > retMaxSize){
                retMaxSize = maxSize[i];
                ret = maxSizeCount[i];
            }
            else if(maxSize[i] == retMaxSize){
                ret += maxSizeCount[i];
            }
        }
        return ret;
    }
};

int main(){
    Solution c;
    std::vector<int> t = {1, 1, 1, 2, 2 ,2 ,3 ,3, 3};
    //std::vector<int> t = {3, 1, 2};
    //std::vector<int> t = {2, 2, 2, 2, 2};
    std::cout << c.findNumberOfLIS(t);
}