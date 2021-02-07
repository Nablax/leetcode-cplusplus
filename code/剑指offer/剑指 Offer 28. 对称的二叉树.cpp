// 剑指 Offer 28. 对称的二叉树
//请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
//
//例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
//
//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3
//但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
//
//    1
//   / \
//  2   2
//   \   \
//   3    3
//
//
//
//示例 1：
//
//输入：root = [1,2,2,3,4,4,3]
//输出：true
//示例 2：
//
//输入：root = [1,2,2,null,3,null,3]
//输出：false

//https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//两个节点两个节点进行递归判断
class Solution {
public:
    bool helper(TreeNode *root1, TreeNode *root2){
        if(root1 and root2) return root1->val == root2->val and helper(root1->left, root2->right) and helper(root1->right, root2->left);
        return !root1 and !root2;
    }
    bool isSymmetric(TreeNode* root) {
        return !root or helper(root->left, root->right);
    }
};