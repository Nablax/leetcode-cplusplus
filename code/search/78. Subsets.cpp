// 78. Subsets
//
// https://leetcode.com/problems/subsets/
// Given a set of distinct integers, nums, return all possible subsets (the power set).
//
//Note: The solution set must not contain duplicate subsets.

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
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<int>& nums, int low, int high){
        if(low == high)
            return;
        for(int i = low; i < high; i++){
            tmp.push_back(nums[i]);
            res.push_back(tmp);
            dfs(nums, i + 1, high);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        tmp.reserve(nums.size());
        dfs(nums, 0, nums.size());
        res.push_back(tmp);
        return res;
    }
};

int main(){
    Solution c;
    vector<int> tmp = {1, 2};
    auto res = c.subsets(tmp);
//    for(auto &x: res)
//        cout << x << endl;
int a=  1;
}