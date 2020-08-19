//653. Two Sum IV - Input is a BST
//
//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
//unfold an BSTs into a sequential array, then find the sum will be much easier.

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
        if(!root)
            return;
        BSTtoArray(root->left);
        nums.push_back(root->val);
        BSTtoArray(root->right);
    }
    std::vector<int> inorderTraversal(TreeNode* root) {
        BSTtoArray(root);
        return nums;
    }
private:
    std::vector<int> nums;
};