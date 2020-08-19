// Path Sum III
// https://leetcode.com/problems/path-sum-iii/

//You are given a binary tree in which each node contains an integer value.
//
//Find the number of paths that sum to a given value.
//
//The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
//
//The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

#include <map>
#include <iostream>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    void dfs(TreeNode *node, int sumBef){
        if(!node)
            return;
        int pro = sumBef + node->val;
        if(nodeSum.find(pro - sum1) != nodeSum.end()){
            res += nodeSum[pro - sum1];
        }
        nodeSum[pro] += 1;
        dfs(node->left, pro);
        dfs(node->right, pro);
        nodeSum[pro] -= 1;
    }
    int pathSum(TreeNode* root, int sum) {
        sum1 = sum;
        res = 0;
        nodeSum[0] = 1;
        dfs(root, 0);
        return res;
    }

private:
    std::unordered_map<int, int> nodeSum;
    int sum1;
    int res;
};

int main(){
    std::map<int, int> a;
    a[0] += 1;
    std::cout<<a[0];
}