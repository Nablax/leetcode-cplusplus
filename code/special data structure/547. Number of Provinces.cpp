// 547. Number of Provinces
// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
//
//A province is a group of directly or indirectly connected cities and no other cities outside of the group.
//
//You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
//
//Return the total number of provinces.

//Union find
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
    std::vector<int> uf;
    void unionRoot(int ind1, int ind2){
        int root1 = findRoot(ind1), root2 = findRoot(ind2);
        if(root1 == root2) return;
        if(uf[root1] == uf[root2]) uf[root1]--;
        if(uf[root1] < uf[root2]){
            uf[root2] = root1;
        }
        else{
            uf[root1] = root2;
        }
    }
    int findRoot(int x){
        if(uf[x] < 0) return x;
        return uf[x] = findRoot(uf[x]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int res = 0;
        uf.resize(n, -1);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(isConnected[i][j]){
                    unionRoot(i, j);
                }
            }
        }
        for(auto &x: uf){
            if(x < 0) res++;
        }
        return res;
    }
};

//void test(){
//    Solution c;
//    std::vector<int > testcase1 = {1,5,6,2};
//    std::vector<int > testcase2 = {1,2,3,6,5,4};
//    std::vector<int > testcase3 = {1,3,3,3,2,4,2,1,2};
//    int ans1 = 1, ans2 = 3, ans3 = 4;
////    std::cout<< (c.createSortedArray(testcase1) == ans1);
////    std::cout<< (c.createSortedArray(testcase2) == ans2);
//    std::cout<< (c.createSortedArray(testcase3) == ans3);
//
//}

int main(){
    //test();
}