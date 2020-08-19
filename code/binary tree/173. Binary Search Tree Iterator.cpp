//173. Binary Search Tree Iterator
//
//https://leetcode.com/problems/binary-search-tree-iterator/
//Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
//
//Calling next() will return the next smallest number in the BST.

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

class BSTIterator {
public:

    BSTIterator(TreeNode* root) {
        curNode = root;
    }

    /** @return the next smallest number */
    int next() {
        int tmp=0;
        while(curNode){
            if(!curNode->left){
                tmp = curNode->val;
                curNode = curNode->right;
                return tmp;
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
                    tmp = curNode->val;
                    curNode = curNode->right;
                    return tmp;
                }
            }
        }
        return tmp;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return curNode!= nullptr;
    }
private:
    TreeNode *curNode;
};