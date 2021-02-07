// 1641. Count Sorted Vowel Strings
// https://leetcode.com/problems/count-sorted-vowel-strings/
// Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.
//
//A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.
//
//
//
//Example 1:
//
//Input: n = 1
//Output: 5
//Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
//Example 2:
//
//Input: n = 2
//Output: 15
//Explanation: The 15 sorted strings that consist of vowels only are
//["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
//Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
//Example 3:
//
//Input: n = 33
//Output: 66045
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
    int countVowelStrings(int n) {
        int res = 5;
        std::vector<int> count(5, 1);
        for(int i = 2; i <= n ; i++){
            for(int j = 0; j < 5; j++){
                for(int k = j + 1; k < 5; k++){
                    count[j] += count[k];
                    res += count[k];
                }
            }
        }
        return res;
    }
};

void test(){
    Solution c;
    std::vector<int> testcase1_1 = {1};
    int testcase1_2 = 1;

    //cout << c.findKthLargest(testcase1_1, testcase1_2);

}

int main(){
    test();
}