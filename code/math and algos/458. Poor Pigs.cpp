// 458. Poor Pigs
// https://leetcode.com/problems/poor-pigs/
// There are 1000 buckets, one and only one of them is poisonous, while the rest are filled with water. They all look identical. If a pig drinks the poison it will die within 15 minutes. What is the minimum amount of pigs you need to figure out which bucket is poisonous within one hour?
//
//Answer this question, and write an algorithm for the general case.

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
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int times = (float)minutesToTest / minutesToDie;
        int res = 0;
        while(pow(times + 1, res) < buckets){
            res++;
        }
        return res;
    }
};