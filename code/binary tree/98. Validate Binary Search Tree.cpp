//98. Validate Binary Search Tree
//
//https://leetcode.com/problems/validate-binary-search-tree/
//Given the root of a binary tree, determine if it is a valid binary search tree (BST).
//
//A valid BST is defined as follows:
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.

#include <queue>
#include <algorithm>
#include <unordered_map>
#include <map>

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
    void BSTtoArray(TreeNode* root){
        if(!root or !correctBST)
            return;
        BSTtoArray(root->left);
        if(root->val <= curMax){
            correctBST = false;
            return;
        }
        curMax = root->val;
        BSTtoArray(root->right);
    }
    bool isValidBST(TreeNode* root) {
        correctBST = true;
        curMax = INT64_MIN;
        BSTtoArray(root);
        return correctBST;
    }

private:
    bool correctBST;
    long long curMax;
};