//94. Binary Tree Inorder Traversal
//
//https://leetcode.com/problems/binary-tree-inorder-traversal/
//Given a binary tree, return the inorder traversal of its nodes' values.
//Recursive solution is trivial, could you do it iteratively?

//Morris traversal:
//1. Initialize current as root
//2. While current is not NULL
//   If the current does not have left child
//      a) Print current’s data
//      b) Go to the right, i.e., current = current->right
//   Else
//      a) Make current as the right child of the rightmost
//         node in current's left subtree
//      b) Go to this left child, i.e., current = current->left

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
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> nums;
        auto curNode = root;
        while(curNode){
            if(!curNode->left){
                nums.push_back(curNode->val);
                curNode = curNode->right;
            }
            else{
                TreeNode *predecessor = curNode->left;
                while(predecessor->right and predecessor->right != curNode)
                    predecessor = predecessor->right; // set the curNode's left child's rightmost node's right node to curNode
                if(!predecessor->right){
                    //If the rightmost right child hasn't been set, set it to the curNode to go back to curNode after this rightmost node is iterated
                    predecessor->right = curNode;
                    curNode = curNode->left;
                }
                else{
                    //Here indicates that the left node of the curNode has been iterated.
                    //So push the curNode value and go to the right node.
                    predecessor->right = nullptr;
                    nums.push_back(curNode->val);
                    curNode = curNode->right;
                }
            }
        }
        return nums;
    }
};