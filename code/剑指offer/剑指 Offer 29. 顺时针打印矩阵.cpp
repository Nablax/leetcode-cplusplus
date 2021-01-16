// 剑指 Offer 29. 顺时针打印矩阵
// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
//
// 
//
//示例 1：
//
//输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]
//示例 2：
//
//输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//旋转打印，最后一定剩下只有一行或者一列或者单个元素，此时进行单独处理就行
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