// 1291. Sequential Digits
//
// https://leetcode.com/problems/sequential-digits/
// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
//
//Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

//note: very interesting solution with BFS
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
using namespace std;

class Solution {
public:
    int retSeqFig(int start, int len){
        int res = 0;
        if(start + len > 10)
            return -1;
        while(len--){
            res = res * 10 + start;
            start++;
        }
        return res;
    }
    vector<int> sequentialDigits(int low, int high) {
        auto slow = to_string(low);
        auto shigh = to_string(high);
        vector<int> res;
        int start, len = slow.size();
        while(len <= shigh.size()){
            start = 1;
            if(len == slow.size())
                start = slow[0] - '0';
            while(start + len - 1 < 10){
                auto tmp = retSeqFig(start, len);
                if(tmp > high or tmp < 0)
                    break;
                if(tmp >= low)
                    res.push_back(tmp);
                start++;
            }
            len++;
        }
        return res;
    }
};

class Solution1 {
public:
    vector<int> sequentialDigits(int l, int h) {
        queue<int> q;
        for(int i = 1; i <= 9; i++) {
            q.push(i);
        }
        vector<int> ret;
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            if(f <= h && f >= l) {
                ret.push_back(f);
            }
            if(f > h)
                break;
            int num = f % 10;
            if(num < 9) {
                q.push(f * 10 + (num + 1));
            }
        }
        return ret;
    }
};

int main(){
    Solution1 c;
    auto res = c.sequentialDigits(100, 1234);
    for(auto &x: res)
        cout << x << endl;
}