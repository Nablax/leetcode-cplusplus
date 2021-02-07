//剑指 Offer 56 - II. 数组中数字出现的次数 II
//在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
//https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/

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


// 记录每一位数字个数，最后对每一位mod3就是最终的数字
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::vector<int> count(32, 0);
        for(auto x: nums){
            int i = 0;
            while(x){
                count[i++] += (x & 1);
                x >>= 1;
            }
        }
        int res = 0;
        for(auto it = count.rbegin(); it != count.rend(); it++){
            res <<= 1;
            res += (*it % 3);
        }
        return res;
    }
};

// 把ab当作三进制的解法，太妙了
// 这样理解,这是相当于是三进制,one表示第一次出现,two表示第二次出现
// 第一次出现时 one = 1 two = 0 第二次出现时 one = 0 two = 1 第三次出现时 one = 0 two = 0
// 通过 one/two ^ num就可以将数据保留到相应的数字里(相当于置1), 而后面的 &~one/two意思是就是判断是否需要进位
// 因为one = 1 two = 1 是表示 3 此时 one = 0 two = 0
class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for(auto &num: nums){
            a = (a ^ num) & ~b;
            b = (b ^ num) & ~a;
        }
        return a;
    }
};