// 279. Perfect Squares
//
// https://leetcode.com/problems/perfect-squares/
// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <iostream>
#include <cmath>

class Solution {
public:
    Solution(){
        a.resize(10000, 0);
        for(int i = 1; i < 100; i++){
            a[i * i] = 1;
        }
    }
    int getNumSquares(int n, int i){
        if(a[n]) return a[n];
        a[n] = n;
        for(; i <= sqrt(n); i++){
            a[n] = std::min(1 + getNumSquares(n - i * i, i), a[n]);
        }
        return a[n];
    }
    int numSquares(int n) {
        return getNumSquares(n, 1);
    }
    std::vector<int> a;
};

class Solution1 {
public:
    Solution1(){
        s.resize(10000, 0);
        s[1] = 1;
    }
    int numSquares(int n) {
        if(s[n]) return s[n];
        if (n == 0) return 0;
        int num = 2, res = n;
        while (num * num <= n)
        {
            int a = n / (num * num), b = n % (num * num);
            res = std::min(res, a + numSquares(b));
            num++;
        }
        s[n] = res;
        return res;
    }
    std::vector<int> s;
};