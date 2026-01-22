class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        while (true) {
            bool sorted = true;
            int n = nums.size();
            for (int i = 1; i < n; i++) {
                if (nums[i] < nums[i-1]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted) break;
            int minSum = INT_MAX;
            int idx = 0;
            for (int i = 0; i < n - 1; i++) {
                int sum = nums[i] + nums[i+1];
                if (sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }
            nums[idx] = nums[idx] + nums[idx+1];
            nums.erase(nums.begin() + idx + 1);
            count++;
        }
        return count;
    }
};
