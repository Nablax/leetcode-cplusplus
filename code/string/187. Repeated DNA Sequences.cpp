// 187. Repeated DNA Sequences
// https://leetcode.com/problems/repeated-dna-sequences/
//
// All DNA is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T', for example: "ACGAATTCCG".
// When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//
// Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

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
    vector<string> findRepeatedDnaSequences(string s) {
        std::unordered_map<std::string, int> dic;
        std::vector<std::string> res;
        if(s.size() <= 10)
            return res;
        string tmp = s.substr(0, 10);
        dic[tmp]++;
        for(int i = 10; i < s.size(); i++){
            tmp = tmp.substr(1, 9) + s[i];
            dic[tmp]++;
            if(dic[tmp] == 2)
                res.push_back(tmp);
        }
        return res;
    }
};
// C++ 17 string View
class Solution1 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string_view, int> seen;
        vector<string> result;
        for(int i = 0, j = s.size()-10; i <= j; ++i){
            auto view = string_view(&s[i], 10);
            auto &count = seen[view];
            if(count++ == 1)
                result.emplace_back(view);
        }
        return result;
    }
};

//bitset
class Solution2 { // bitset
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        bitset<1 << 20> m1, m2;  // faster than map/set
        int t = 0, k = (1 << 20) - 1;
        for (int i = 0; i < s.size(); ++i)
        {
            t = t << 2 & k | s[i] >> 1 & 3;  // compare, k as mask   // last 3 bits of 65 67 71 84 -> 001 011 111 100
            if (i < 9) continue;
            if (!m2[t] && m1[t])  // compare
            {
                res.push_back(s.substr(i - 9, 10));
                m2.set(t);
            }
            else m1.set(t);
        }
        return res;
    }
};