// 738. Monotone Increasing Digits
//
// https://leetcode.com/problems/monotone-increasing-digits/
// Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.
//
//(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)
#include <algorithm>
#include <unordered_map>
#include <map>
#include <iostream>
#include <cmath>
#include <set>
#include <list>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        while(true){
            if(version1.empty() and version2.empty())
                return 0;
            auto w1 = version1.find('.');
            auto w2 = version2.find('.');
            int tmp1 = 0, tmp2 = 0;
            if(w1 != string::npos){
                tmp1 = std::stoi(version1.substr(0, w1));
                version1 = version1.substr(w1 + 1);
            }
            else if(!version1.empty()){
                tmp1 = std::stoi(version1);
                version1.clear();
            }
            if(w2 != string::npos){
                tmp2 = std::stoi(version2.substr(0, w2));
                version2 = version2.substr(w2 + 1);
            }
            else if(!version2.empty()){
                tmp2 = std::stoi(version2);
                version2.clear();
            }
            if(tmp1 > tmp2)
                return 1;
            if(tmp1 < tmp2)
                return -1;
        }
    }
};

int main(){
    Solution c;
    c.compareVersion("1.0", "1");

}