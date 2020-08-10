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

int main(){
    std::vector<int> a = {3,2,1,5,6,4};
    Solution c;
    int b = c.findKthLargest(a, 2);
    int aa = 1;
}
