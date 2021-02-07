// 5. Longest Palindromic Substring
// Given a string s, return the longest palindromic substring in s.
//
//
//
//Example 1:
//
//Input: s = "babad"
//Output: "bab"
//Note: "aba" is also a valid answer.
//Example 2:
//
//Input: s = "cbbd"
//Output: "bb"
//Example 3:
//
//Input: s = "a"
//Output: "a"
//Example 4:
//
//Input: s = "ac"
//Output: "a"

//https://leetcode.com/problems/longest-palindromic-substring/
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

//解法1，从较小的回文子串开始往两边expand找更大的子串
class Solution {
private:
    int pivot, maxLen;
    void searchSubStr(const string &s, int l, int r){
        while(l >= 0 and r < s.size() and s[l] == s[r]){
            l--;
            r++;
        }
        if(r - l - 1 > maxLen){
            maxLen = r - l - 1;
            pivot = ++l;
        }
    }
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        pivot = 0, maxLen = 1;
        for(int i = 1; i < s.size(); i++){
            searchSubStr(s, i - 1, i + 1);
            searchSubStr(s, i - 1, i);
        }
        return s.substr(pivot, maxLen);
    }
};

//solution 2, the manacher's algorithm: O(n)


//void test(){
//    Solution1 c;
//    std::vector<int> testcase1_1 = {1,6,3,2,5};
//    int testcase1_2 = 1;
//
//    cout << c.verifyPostorder(testcase1_1);
//
//}
//
//int main(){
//    test();
//}