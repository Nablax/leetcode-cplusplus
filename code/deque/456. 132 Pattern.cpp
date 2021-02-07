// 456. 132 Pattern
// https://leetcode.com/problems/132-pattern/
// Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
//
// Return true if there is a 132 pattern in nums, otherwise, return false.
//
// Follow up: The O(n^2) is trivial, could you come up with the O(n logn) or the O(n) solution?
// 找132不好找，反着找231就好找多了
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
    bool find132pattern(vector<int>& nums) {
        int n2 = INT32_MIN;
        std::deque<int> st;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] < n2)
                return true;
            while(!st.empty() and nums[i] > st.back()){
                n2 = st.back();
                st.pop_back();
            }
            st.push_back(nums[i]);
        }
        return false;
    }
};

int main(){
    Solution c;
    std::vector<int> test = {-2,1,2,-2,1,2};
    std::cout << c.find132pattern(test);

}