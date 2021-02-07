// 剑指 Offer 33. 二叉搜索树的后序遍历序列
// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
//
// 
//
//参考以下这颗二叉搜索树：
//
//     5
//    / \
//   2   6
//  / \
// 1   3
//示例 1：
//
//输入: [1,6,3,2,5]
//输出: false
//示例 2：
//
//输入: [1,3,2,6,5]
//输出: true
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//后序遍历的性质，最后一个元素一定是根节点，然后根节点前面一定被分为至少两块，前一块小于根，后一块大于根
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

//解法1，暴力解法，逆向读后续数组建立二叉搜索树，再将建立的二叉搜索树后序遍历比较结果
class Solution {
private:
    struct TreeNode{
        int val;
        TreeNode *left, *right;
        TreeNode(int v): val(v), left(nullptr), right(nullptr){};
    };
    std::vector<int> res;
    void postorderfind(TreeNode *root){
        if(!root) return;
        postorderfind(root->left);
        postorderfind(root->right);
        res.push_back(root->val);
    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        TreeNode *cur = nullptr, *root = nullptr;
        for(auto it = std::rbegin(postorder); it != std::rend(postorder); it++){
            if(!cur) {
                cur = new TreeNode(*it);
                root = cur;
            }
            else{
                while(true){
                    if(*it < cur->val){
                        if(cur->left) cur = cur->left;
                        else{
                            cur->left = new TreeNode(*it);
                            break;
                        }
                    }
                    if(*it > cur->val){
                        if(cur->right) cur = cur->right;
                        else{
                            cur->right = new TreeNode(*it);
                            break;
                        }
                    }
                }
            }
            cur = root;
        }
        res.reserve(postorder.size());
        postorderfind(root);
        return res == postorder;
    }
};
//解法2，就是分块检测左子树和右子树相对于根的大小是否合法，这里用了点迭代器骚操作
class Solution1 {
public:
    using T = std::vector<int>::iterator;
    bool verifyPostorder(vector<int>& postorder) {
        return postorder.empty() or verify(postorder, std::begin(postorder), --std::end(postorder));
    }
    bool verify(std::vector<int>& postorder, const T &begin, const T &end){
        if(std::distance(begin, end) <= 0) return true;
        auto it = begin, mid = begin;
        for(it = begin; it != end; it++){
            if(*it > *end) break;
        }
        mid = it;
        for(; it != end; it++){
            if(*it < *end) return false;
        }
        return verify(postorder, begin, mid - 1) and verify(postorder, mid, end - 1);
    }
};

void test(){
    Solution1 c;
    std::vector<int> testcase1_1 = {1,6,3,2,5};
    int testcase1_2 = 1;

    cout << c.verifyPostorder(testcase1_1);

}

int main(){
    test();
}