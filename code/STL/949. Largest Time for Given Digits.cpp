// 949. Largest Time for Given Digits
//
// https://leetcode.com/problems/largest-time-for-given-digits/
// Given an array of 4 digits, return the largest 24 hour time that can be made.
//
// The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.
//
// Return the answer as a string of length 5.  If no valid time can be made, return an empty string.
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;


class Solution {
public:
    int cbTime(int x, int y, bool isHour){
        int tmp1 = x * 10 + y;
        int tmp2 = y * 10 + x;
        if(isHour){
            if(tmp1 >= 24)
                tmp1 = -1;
            if(tmp2 >= 24)
                tmp2 = -1;
            return max(tmp1, tmp2);
        }
        else{
            if(tmp1 >= 60)
                tmp1 = -1;
            if(tmp2 >= 60)
                tmp2 = -1;
            return max(tmp1, tmp2);
        }
    }

    void string_to_time(int &tmp1, int &tmp2, int &max_h, int &max_min, string &s){
        if(tmp1 == -1 or tmp2 == -1)
            return;
        if(tmp1 < max_h)
            return;
        if(tmp1 == max_h and tmp2 <= max_min)
            return;
        s = (tmp1 >= 10 ? "": "0") + to_string(tmp1) + string(":") +(tmp2 >= 10 ? "": "0")+ to_string(tmp2);
        max_h = tmp1;
        max_min = tmp2;
    }

    string largestTimeFromDigits(vector<int>& A) {
        string res;
        int hour=-1, minutes=-1;
        vector<vector<int>> combine = {{A[0], A[1], A[2], A[3]}, {A[0], A[2], A[1], A[3]}, {A[0], A[3], A[1], A[2]}};
        int max_h = -1, max_min = -1;
        for(auto &x: combine){
            int tmp1 = -1, tmp2 = -1;
            tmp1 = cbTime(x[0], x[1], true);
            tmp2 = cbTime(x[2], x[3], false);
            string_to_time(tmp1, tmp2, max_h, max_min, res);
            tmp1 = cbTime(x[2], x[3], true);
            tmp2 = cbTime(x[0], x[1], false);
            string_to_time(tmp1, tmp2, max_h, max_min, res);
        }
        return res;
    }
};

class Solution1 {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string res;
        sort(A.begin(), A.end());
        do {
            string hour = {char(A[0] + '0'), char(A[1] + '0')}, minute = {char(A[2] + '0'), char(A[3] + '0')};
            res = (hour <= "23" && minute <= "59") ? (hour + ":" + minute) : res;
        } while(next_permutation(A.begin(), A.end()));
        return res;
    }
};