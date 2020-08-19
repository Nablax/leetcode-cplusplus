//98. Validate Binary Search Tree
//
//https://leetcode.com/problems/validate-binary-search-tree/
//unfold an BSTs into an array, if the array is sequential then it's right

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