// 845. Longest Mountain in Array
// https://leetcode.com/problems/longest-mountain-in-array/
// Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:
//
//B.length >= 3
//There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
//(Note that B could be any subarray of A, including the entire array A.)
//
//Given an array A of integers, return the length of the longest mountain.
//
//Return 0 if there is no mountain.

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
    int longestMountain(vector<int>& A) {
        if(A.size() < 3)
            return 0;
        bool stateUp = true;
        int res = 0, tmpCount = 1;
        for(int i = 1; i < A.size(); i++){
            if(A[i] == A[i-1]){
                if(tmpCount >= 3 and !stateUp){
                    res = std::max(tmpCount, res);
                }
                tmpCount = 1;
            }
            else if(A[i] > A[i - 1]){
                if(stateUp){
                    tmpCount++;
                }
                else{
                    stateUp = true;
                    res = std::max(tmpCount, res);
                    tmpCount = 2;
                }
            }
            else{
                if(!stateUp){
                    tmpCount++;
                }
                else if(tmpCount > 1){
                    stateUp = false;
                    tmpCount++;
                }
            }
        }
        if(!stateUp and tmpCount >= 3){
            res = std::max(tmpCount, res);
        }
        return res;
    }
};

//peak and foot
class Solution1 {
public:
    int longestMountain(vector<int>& A) {
        int foot = 0, peak = 0, ans = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i-1] < A[i]) {
                if (peak != i - 1) {
                    foot = i - 1;
                }
                peak = i;
            } else if (A[i-1] > A[i]) {
                if (peak > foot) {
                    ans = max(ans, i - foot + 1);
                }
            } else {
                peak = foot = i;
            }
        }
        return ans;
    }
};