// 1329. Sort the Matrix Diagonally
//A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].
//
//Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.
// https://leetcode.com/problems/sort-the-matrix-diagonally/
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
    void insertionSort(std::vector<std::vector<int>> &mat, int x, int y){
        int m = mat.size(), n = mat[0].size();
        int p, q, tmp;
        for(int i = x + 1, j = y + 1; i < m and j < n; i++, j++){
            tmp = mat[i][j];
            for(p = i, q = j; p > 0 and q > 0 and tmp < mat[p - 1][q - 1]; p--, q--){
                mat[p][q] = mat[p - 1][q - 1];
            }
            mat[p][q] = tmp;
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i = 0; i < mat.size(); i++){
            insertionSort(mat, i, 0);
        }
        for(int j = 1; j < mat[0].size(); j++){
            insertionSort(mat, 0, j);
        }
        return mat;
    }
};