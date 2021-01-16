// 剑指 Offer 45. 把数组排成最小的数
// 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//
// 
//
//示例 1:
//
//输入: [10,2]
//输出: "102"
//示例 2:
//
//输入: [3,30,34,5,9]
//输出: "3033459"
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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


class Solution {
private:
    int toFind;
    void moveMiddleToEnd(std::vector<int>& nums, const int &left, const int &right){
        int front = left, middle = (left + right) / 2, end = right;
        if(nums[front] > nums[middle]) std::swap(nums[front], nums[middle]);
        if(nums[middle] > nums[end]) std::swap(nums[middle], nums[end]);
        if(nums[front] > nums[middle]) std::swap(nums[front], nums[middle]);
        std::swap(nums[middle], nums[end - 1]);
    }
    int halfQuickSort(vector<int> &nums, const int &left, const int &right){
        if(right - left < 5) return insertionSort(nums, left, right);
        moveMiddleToEnd(nums, left, right);
        int l = left, r = right - 1, pivot = right - 1;
        while(true){
            while(nums[++l] < nums[pivot]){}
            while(nums[--r] > nums[pivot]){}
            if(l < r) std::swap(nums[l], nums[r]);
            else break;
        }
        std::swap(nums[l], nums[pivot]);
        if(l == toFind) return nums[l];
        return l > toFind? halfQuickSort(nums, left, l - 1): halfQuickSort(nums, l + 1, right);
    }
    int insertionSort(vector<int> &nums, const int &left, const int &right){
        auto begin = std::begin(nums) + left, end = std::begin(nums) + right + 1;
        for(auto i = begin + 1; i != end; i++){
            auto tmp = *i;
            auto j = i;
            for(; j != begin and tmp < *(j - 1); j--){
                *j = *(j - 1);
            }
            *j = tmp;
        }
        return nums[toFind];
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        toFind = nums.size() - k;
        return halfQuickSort(nums, 0, nums.size() - 1);
    }
};

void test(){
    Solution c;
    std::vector<int> testcase1_1 = {1};
    int testcase1_2 = 1;

    cout << c.findKthLargest(testcase1_1, testcase1_2);

}

int main(){
    test();
}