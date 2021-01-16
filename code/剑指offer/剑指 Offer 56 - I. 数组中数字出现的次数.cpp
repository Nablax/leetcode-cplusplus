// 剑指 Offer 56 - I. 数组中数字出现的次数
// 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
//
// 
//
//示例 1：
//
//输入：nums = [4,1,4,6]
//输出：[1,6] 或 [6,1]
//示例 2：
//
//输入：nums = [1,2,10,4,1,4,3,3]
//输出：[2,10] 或 [10,2]
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//太妙了，分组进行异或，牛逼！！！！

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
    vector<int> singleNumbers(vector<int>& nums) {
        int val = 0;
        std::vector<int> res(2, 0);
        for(auto &num: nums) val ^= num;
        val = val & (-val);
        for(auto &num: nums){
            if(val & num) res[0] ^= num;
            else res[1] ^= num;
        }
        return res;
    }
};