// 剑指 Offer 49. 丑数
// 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
//
// 
//
//示例:
//
//输入: n = 10
//输出: 12
//解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/chou-shu-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


// 三指针每次比大小，蛮有趣的
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
    int nthUglyNumber(int n) {
        std::vector<int> uNums(n, 1), i235(3, 0), n235 = {2, 3, 5}, curVal = {2, 3, 5};
        for(int i = 1; i < n; i++){
            uNums[i] = std::min(curVal[0], std::min(curVal[1], curVal[2]));
            for(int j = 0; j < 3; j++){
                if(uNums[i] == curVal[j]) curVal[j] = uNums[++i235[j]] * n235[j];
            }
        }
        return uNums.back();
    }
};

//void test(){
//    Solution c;
//    std::vector<int > testcase1 = {1,5,6,2};
//    std::vector<int > testcase2 = {1,2,3,6,5,4};
//    std::vector<int > testcase3 = {1,3,3,3,2,4,2,1,2};
//    int ans1 = 1, ans2 = 3, ans3 = 4;
////    std::cout<< (c.createSortedArray(testcase1) == ans1);
////    std::cout<< (c.createSortedArray(testcase2) == ans2);
//    std::cout<< (c.createSortedArray(testcase3) == ans3);
//
//}

int main(){
    //test();
}