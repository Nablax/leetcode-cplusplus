//230. Kth Smallest Element in a BST
//
//https://leetcode.com/problems/kth-smallest-element-in-a-bst/
//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//Easy inorder traversal

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
    void findk(TreeNode *root){
        if(!root or !count)
            return;
        findk(root->left);
        count--;
        if(!count) {
            res = root->val;
            return;
        }
        findk(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        res = 0;
        findk(root);
        return res;
    }

private:
    int res, count;
};