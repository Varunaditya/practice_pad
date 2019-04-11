class Solution {
public:
    int partition(vector<int> &nums, int left, int right, int pivot){
        while(left <= right){
            while(nums[left] > pivot){
                left++;
            }
            while(nums[right] < pivot){
                right--;
            }
            if (left <= right){
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
                right--;
            }
        }
        return left;
    }
    
    void quick_sort(vector<int> &nums, int left, int right){
        if (left >= right) return;
        int pivot = nums[(left + right) / 2];
        int position = partition(nums, left, right, pivot);
        quick_sort(nums, left, position - 1);
        quick_sort(nums, position, right);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        quick_sort(nums, 0, nums.size() -1);
        return nums[k - 1];
    }
};
