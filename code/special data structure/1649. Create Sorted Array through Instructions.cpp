// 1649. Create Sorted Array through Instructions
// Given an integer array instructions, you are asked to create a sorted array from the elements in instructions. You start with an empty container nums. For each element from left to right in instructions, insert it into nums. The cost of each insertion is the minimum of the following:
//
//The number of elements currently in nums that are strictly less than instructions[i].
//The number of elements currently in nums that are strictly greater than instructions[i].
//For example, if inserting element 3 into nums = [1,2,3,5], the cost of insertion is min(2, 1) (elements 1 and 2 are less than 3, element 5 is greater than 3) and nums will become [1,2,3,3,5].
//
//Return the total cost to insert all elements from instructions into nums. Since the answer may be large, return it modulo 109 + 7

// A brand new data structure binary indexed tree, very fun
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
    std::vector<int> c;
    void update(int x) {
        while (x < 100001) {
            c[x]++;
            x += x & -x;
        }
    }
    int get(int x) {
        int res = 0;
        while (x > 0) {
            res += c[x];
            x -= x & -x;
        }
        return res;
    }
public:
    int createSortedArray(vector<int>& A) {
        c.resize(100001, 0);
        int res = 0, n = A.size(), mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            res = (res + min(get(A[i] - 1), i - get(A[i]))) % mod;
            update(A[i]);
        }
        return res;
    }
};

void test(){
    Solution c;
    std::vector<int > testcase1 = {1,5,6,2};
    std::vector<int > testcase2 = {1,2,3,6,5,4};
    std::vector<int > testcase3 = {1,3,3,3,2,4,2,1,2};
    int ans1 = 1, ans2 = 3, ans3 = 4;
//    std::cout<< (c.createSortedArray(testcase1) == ans1);
//    std::cout<< (c.createSortedArray(testcase2) == ans2);
    std::cout<< (c.createSortedArray(testcase3) == ans3);

}

int main(){
    test();
}