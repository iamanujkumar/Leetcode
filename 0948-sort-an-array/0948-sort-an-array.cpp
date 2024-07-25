class Solution {
public:
    void merge(vector<int> &nums, int low, int mid, int high) {
        vector<int> temp(high - low + 1);
        int left = low;   
        int right = mid + 1;
        int k = 0;
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp[k++] = nums[left++];
            } else {
                temp[k++] = nums[right++];
            }
        }
        while (left <= mid) {
            temp[k++] = nums[left++];
        }

        while (right <= high) {
            temp[k++] = nums[right++];
        }
        for (int i = 0; i < temp.size(); i++) {
            nums[low + i] = temp[i];
        }
    }

    void mergeSort(vector<int> &nums, int low, int high) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid); 
        mergeSort(nums, mid + 1, high); 
        merge(nums, low, mid, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return nums;
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
