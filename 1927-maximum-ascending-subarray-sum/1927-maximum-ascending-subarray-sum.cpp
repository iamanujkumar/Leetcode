class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int maxi = nums[0];
        int currentSum = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i];
            } else {
                maxi = max(maxi, currentSum);
                currentSum = nums[i];
            }
        }
        maxi = max(maxi, currentSum);
        return maxi;
    }
};
