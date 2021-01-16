# include <vector>
class Solution {
public:
    int findBase(std::vector<int>& nums, int left, int right){
        int tmpBase = nums[left];
        while(left < right){
            while(left < right and nums[right] <= tmpBase)
                right--;
            if(left < right)
                nums[left++] = nums[right];
            while(left < right and nums[left] >= tmpBase)
                left++;
            if(left < right)
                nums[right--] = nums[left];
        }
        nums[left] = tmpBase;
        return left;
    }
    void quicksort(std::vector<int>& nums, int left, int right){
        if (right <= left){
            res = nums[left];
            return;
        }
// here is a trick, to start the sort from the middle
        int mid = (left + right) / 2;
        std::swap(nums[mid], nums[left]);

        int base = findBase(nums, left, right);
        if(kth == base){
            res = nums[base];
            return;
        }
        if(kth < base)
            quicksort(nums, left, base - 1);
        else if (kth > base)
            quicksort(nums, base + 1, right);
    }
    int findKthLargest(std::vector<int>& nums, int k) {
        kth = k - 1; res = 0;
        quicksort(nums, 0, nums.size() - 1);
        return res;
    }

private:
    int kth;
    int res;
};

//快排，取三个数中位数，更快更好
class Solution1 {
private:
    int toFind;
    void moveMiddleToEnd(std::vector<int>& nums, const int &left, const int &right){
        int front = left, middle = (left + right) / 2, end = right;
        if(nums[front] > nums[middle]) std::swap(nums[front], nums[middle]);
        if(nums[middle] > nums[end]) std::swap(nums[middle], nums[end]);
        if(nums[front] > nums[middle]) std::swap(nums[front], nums[middle]);
        std::swap(nums[middle], nums[end - 1]);
    }
    int halfQuickSort(std::vector<int> &nums, const int &left, const int &right){
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
    int insertionSort(std::vector<int> &nums, const int &left, const int &right){
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
    int findKthLargest(std::vector<int>& nums, int k) {
        toFind = nums.size() - k;
        return halfQuickSort(nums, 0, nums.size() - 1);
    }
};

int main(){
    std::vector<int> a = {3,2,1,5,6,4};
    Solution c;
    int b = c.findKthLargest(a, 2);
    int aa = 1;
}
