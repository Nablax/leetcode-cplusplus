//剑指 Offer 46. 把数字翻译成字符串
//给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
//
// 
//
//示例 1:
//
//输入: 12258
//输出: 5
//解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
    int translateNum(int num) {
        std::deque<int> dig;
        while(num){
            dig.push_front(num % 10);
            num /= 10;
        }
        if(dig.size() < 2) return 1;
        int an_2 = 1, an_1 = 1, an;
        for(int i = 1; i < dig.size(); i++){
            an = an_1;
            if(dig[i - 1] > 0 and dig[i] + dig[i - 1] * 10 < 26) an += an_2;
            an_2 = an_1;
            an_1 = an;
        }
        return an;
    }
};