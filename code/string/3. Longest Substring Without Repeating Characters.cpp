// 3. Longest Substring Without Repeating Characters
//
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Given a string s, find the length of the longest substring without repeating characters.

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
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        int res = 0;
        std::deque<char> st;
        std::unordered_map<char, bool> um;

        for(auto &x: s){
            if(!um[x]){
                st.push_back(x);
            }
            else{
                while(st.front()!=x and !st.empty()){
                    um[st.front()] = false;
                    st.pop_front();
                }
                st.pop_front();
                st.push_back(x);
            }
            um[x] = true;
            res = std::max(res, static_cast<int>(st.size()));
        }
        return res;
    }
};


int main(){
    Solution c;
    string s = "abba";
    std::cout << c.lengthOfLongestSubstring(s);
}