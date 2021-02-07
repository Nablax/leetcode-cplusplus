//剑指 Offer 60. n个骰子的点数
//把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
//
// 
//
//你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。
//
// 
//
//示例 1:
//
//输入: 1
//输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
//示例 2:
//
//输入: 2
//输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof
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
    vector<double> dicesProbability(int n) {
        std::vector<std::vector<double>> res(2);
        res[0].reserve(5 * n + 1);
        res[1].reserve(5 * n + 1);
        int cur = 0, tmpSum = 1;
        res[0].push_back(1);
        for(int i = 0; i < n; i++){
            cur ^= 1;
            tmpSum *= 6;
            res[cur].clear();
            res[cur].resize(5 * i + 6, 0);
            for(int j = 0; j < 5 * i + 1; j++){
                for(int k = 0; k < 6; k++){
                    res[cur][j + k] += res[cur ^ 1][j];
                }
            }
        }
        for(auto &x: res[cur]){
            x /= tmpSum;
        }
        return res[cur];
    }
};