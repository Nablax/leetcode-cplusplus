// 239. Sliding Window Maximum
// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//
//Return the max sliding window.
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
    struct mypair{
        int num, pos;
        mypair(int n, int p):num(n), pos(p){}
    };
    deque<mypair> maxdq;

    void pushMaxDq(int n, int p){
        while(!maxdq.empty() and maxdq.back().num <= n){
            maxdq.pop_back();
        }
        maxdq.emplace_back(n, p);
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        k--;
        std::vector<int> res(n - k, 0);
        int l = 0;
        for(int i = l; i < l + k; i++){
            pushMaxDq(nums[i], i);
        }
        while(l + k < n){
            pushMaxDq(nums[l + k], l + k);
            res[l] = maxdq.front().num;
            if(l++ == maxdq.front().pos) maxdq.pop_front();
        }
        return res;
    }
};

void test(){
    Solution c;
    std::vector<int> testcase1 = {1,3,-1,-3,5,3,6,7};
//    std::vector<int> testcase2 = {5,6,7,8,9};
//    std::vector<int > testcase3 = {3,2,20,1,1,3};

    vector<int> ans1 = {3,3,5,5,6,7};
    int ans2 = -1;
    int ans3 = 5;
//    std::cout<< (c.createSortedArray(testcase1) == ans1);
//    std::cout<< (c.createSortedArray(testcase2) == ans2);
    std::cout<< (c.maxSlidingWindow(testcase1, 3) == ans1);

}

int main(){
    test();
}