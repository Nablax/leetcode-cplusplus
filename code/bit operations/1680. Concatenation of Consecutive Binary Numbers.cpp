// 1680. Concatenation of Consecutive Binary Numbers
// Given an integer n, return the decimal value of the binary string formed
// by concatenating the binary representations of 1 to n in order, modulo 10e9 + 7.
//
//https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
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
    int concatenatedBinary(int n) {
        long res = 0;
        int count = 0, mod = 1e9+7;
        for(int i = 1; i <= n; i++){
            //当第一次发生进位的时候，i和i-1求并必为0
            if((i & (i - 1)) == 0) count++;
            res = (res << count) % mod + i;
        }
        return res % mod;
    }
};