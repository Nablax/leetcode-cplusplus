# include <vector>
// some sort algorithms
class Solution {
public:
    std::vector<int> bubbleSort(std::vector<int>& nums) {
        for(int i = 0; i< nums.size(); i++){
            for(int j = 0; j < nums.size() - 1 - i; j++){
                if(nums[j] > nums[j + 1]){
                    swap(nums, j, j + 1);
                }
            }
        }
        return nums;
    }
    void swap(std::vector<int>& nums, int idx1, int idx2){
        if(idx1 == idx2){ return; }
        nums[idx1] ^= nums[idx2];
        nums[idx2] ^= nums[idx1];
        nums[idx1] ^= nums[idx2];
    }
    int findBase(std::vector<int> &nums, int left, int right){
        int tmpBase = nums[left];
        while (right > left){
            while(right > left and nums[right] >= tmpBase)
                right--;
            if(right > left)
                nums[left++] = nums[right];
            while(right > left and nums[left] <= tmpBase)
                left++;
            if(right > left)
                nums[right--] = nums[left];
        }
        nums[left] = tmpBase;
        return left;
    }
    void quickSort(std::vector<int>& nums, int left, int right) {
        if(right <= left){
            return;
        }
        int base = findBase(nums, left, right);
        quickSort(nums, left, base - 1);
        quickSort(nums, base + 1, right);
    }

    std::vector<int> sortArray(std::vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main(){
    std::vector<int> a = {-4,0,7,4,9,-5,-1,0,-7,-1};
    Solution c;
    c.sortArray(a);
    int cc = 1;
}
