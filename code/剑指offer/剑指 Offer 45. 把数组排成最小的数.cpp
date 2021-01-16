// 剑指 Offer 45. 把数组排成最小的数
// 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//
// 
//
//示例 1:
//
//输入: [10,2]
//输出: "102"
//示例 2:
//
//输入: [3,30,34,5,9]
//输出: "3033459"
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 思路：给排序算法传lambda，对于两个数转化成string，验证a+b < b+a
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
    string minNumber(vector<int>& nums) {
        std::vector<std::string> strnum(nums.size());
        for(int i = 0; i < nums.size(); i++){
            strnum[i] = std::to_string(nums[i]);
        }
        std::sort(std::begin(strnum), std::end(strnum), [](const std::string &a, const std::string &b){return a + b < b + a;});
        std::string res = "";
        for(auto &x: strnum) res += x;
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
    //std::cout<< (c.maxSlidingWindow(testcase1, 3) == ans1);

}

int main(){
    test();
}