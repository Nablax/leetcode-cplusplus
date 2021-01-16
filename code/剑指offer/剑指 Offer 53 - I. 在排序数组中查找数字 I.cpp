// 剑指 Offer 53 - I. 在排序数组中查找数字 I
// https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/submissions/
// 统计一个数字在排序数组中出现的次数。
//示例 1:
//
//输入: nums = [5,7,7,8,8,10], target = 8
//输出: 2
//示例2:
//
//输入: nums = [5,7,7,8,8,10], target = 6
//输出: 0
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 三次二分分别找左右边界做差

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
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int l = 0, r = nums.size() - 1, m;
        while(l <= r){
            m = (r - l) / 2 + l;
            if(nums[m] < target) l = m + 1;
            else if(nums[m] > target) r = m - 1;
            else break;
        }
        if(nums[m] != target) return 0;
        auto oneTarget = m, targetLeft = 0, targetRight = 0;
        l = 0, r = oneTarget;
        while(l <= r){
            m = (r - l) / 2 + l;
            if(nums[m] < target) l = m + 1;
            else if(nums[m] >= target) r = m - 1;
        }
        targetLeft = l;

        l = oneTarget, r = nums.size() - 1;
        while(l <= r){
            m = (r - l) / 2 + l;
            if(nums[m] <= target) l = m + 1;
            else if(nums[m] > target) r = m - 1;
        }

        targetRight = r;
        return targetRight - targetLeft + 1;
    }
};

//优化后两次二分
class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0] == target;
        int l = 0, r = nums.size() - 1, m;
        bool ifind = false;
        while(l <= r){
            m = (r - l) / 2 + l;
            if(nums[m] < target) l = m + 1;
            else if(nums[m] >= target) r = m - 1;
            if(nums[m] == target) ifind = true;
        }
        if(!ifind) return 0;
        auto tmp = r;

        l = r, r = nums.size() - 1;
        while(l <= r){
            m = (r - l) / 2 + l;
            if(nums[m] <= target) l = m + 1;
            else if(nums[m] > target) r = m - 1;
        }
        return l - tmp - 1;
    }
};
