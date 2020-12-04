// 902. Numbers At Most N Given Digit Set
// https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
// Given an array of digits, you can write numbers using each digits[i] as many times as we want.  For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.
//
//Return the number of positive integers that can be generated that are less than or equal to a given integer n.

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
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        if(digits.empty()) return 0;
        int lessI[11] = {0}, equalI[11] = {0};
        for(auto &x: digits){
            equalI[x[0] - '0'] = 1;
            for(int i = 0; i < 11; i++){
                if(x[0] - '0' < i){
                    lessI[i]++;
                }
            }
        }
        int res = 0, lastLegal = 0;
        int last, tmp, dig_count = 0, dig_len = digits.size();
        while(n){
            last = n % 10;
            n /= 10;
            if(n > 0 and last == 0) {
                n -= 1;
                last = last + 10;
            }
            if(dig_count){
                tmp = std::pow(dig_len, dig_count);
                res += tmp - lastLegal;
                lastLegal = lessI[last] * tmp + equalI[last] * lastLegal;
            }
            else lastLegal = lessI[last] + equalI[last];
            res += lastLegal;
            dig_count++;
        }
        return res;
    }
};

int main(){
    std::vector<std::string> input = {"7"};
    int input2 = 100;
    Solution c;
    c.atMostNGivenDigitSet(input, input2);
}