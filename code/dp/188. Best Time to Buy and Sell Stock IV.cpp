// 188. Best Time to Buy and Sell Stock IV
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
//
//Design an algorithm to find the maximum profit. You may complete at most k transactions.
//
//Notice that you may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

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
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& p, int res = 0) {
        for (int i = 1; i < p.size(); ++i) res += max(0, p[i] - p[i - 1]);
        return res;
    }
    int maxProfit(int k, vector<int>& prices) {
        if (k >= prices.size() / 2) return maxProfit(prices);
        vector<int> buys(k + 1, INT_MIN), sells(k + 1, 0);
        for (auto p : prices)
            for (auto i = 1; i <= k; ++i) {
                buys[i] = max(buys[i], sells[i - 1] - p);
                sells[i] = max(sells[i], buys[i] + p);
            }
        return sells[k];
    }
};