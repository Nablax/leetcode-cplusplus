//108. Convert Sorted Array to Binary Search Tree
//
//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//As sorted array, use binary recursive, split the array with the middle value

#include <queue>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <iostream>

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
    void unfold(TreeNode *root){
        if(!root)
            return;
        unfold(root->left);
        std::cout << root->val<<std::endl;
        unfold(root->right);
    }
    void buildTree(TreeNode *&root, int left, int right, std::vector<int>& nums){
        if(right < left)
            return;
        int mid = (left - right) / 2 + right;
        root = new TreeNode(nums[mid]);
        buildTree(root->left, left, mid - 1, nums);
        buildTree(root->right, mid +1 , right, nums);
    }
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;
        TreeNode *root;
        buildTree(root, 0, nums.size()-1, nums);
        return root;
    }
};

int main(){
    Solution c;
    std::vector<int> a = {-3,0,9};
    auto root = c.sortedArrayToBST(a);
    c.unfold(root);
}