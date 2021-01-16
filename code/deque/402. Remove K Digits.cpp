// 402. Remove K Digits
//
// https://leetcode.com/problems/remove-k-digits/
// Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
//
//Note:
//The length of num is less than 10002 and will be ≥ k.
//The given num does not contain any leading zero.
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <iostream>
#include <cmath>
#include <set>
#include <list>
#include <stack>
using namespace std;

// deque solution
class Solution {
public:
    string removeKdigits(const string &num, int k) {
        cout << num.size() << endl;
        deque<char> res;
        for(auto &x: num){
            while(k and !res.empty() and x < res.back()){
                res.pop_back();
                k--;
            }
            res.push_back(x);
        }
        while(k and !res.empty()){
            res.pop_back();
            k--;
        }
        while(!res.empty() and *res.begin() == '0'){
            res.pop_front();
        }
        return res.empty()? "0": string(res.begin(), res.end());
    }
};

class Solution1 {
public:
    string removeKdigits(string num, int k) {
        list<char> res(num.begin(), num.end());
        while(k > 0){
            auto it = res.begin();
            for(auto start = res.begin(); start != res.end(); start++){
                if(*it > *start)
                    break;
                it = start;
            }
            res.erase(it);
            k--;
        }
        auto it = res.begin();
        while(*it == '0'){
            it = res.erase(it);
        }
        return !res.empty() ? string(res.begin(), res.end()): "0";
    }
};

int main(){
    Solution c;
    Solution1 cc;
    cout << c.removeKdigits("123", 1);
}