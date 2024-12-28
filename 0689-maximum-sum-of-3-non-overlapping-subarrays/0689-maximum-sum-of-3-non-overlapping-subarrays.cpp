class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> result(3, 0);
        int maxSum = sum[k] - sum[0];
        for (int i = k; i < n; ++i) {
            if (sum[i + 1] - sum[i + 1 - k] > maxSum) {
                left[i] = i + 1 - k;
                maxSum = sum[i + 1] - sum[i + 1 - k];
            } else {
                left[i] = left[i - 1];
            }
        }
        maxSum = sum[n] - sum[n - k];
        right[n - k] = n - k;
        for (int i = n - k - 1; i >= 0; --i) {
            if (sum[i + k] - sum[i] >= maxSum) {
                right[i] = i;
                maxSum = sum[i + k] - sum[i];
            } else {
                right[i] = right[i + 1];
            }
        }
        maxSum = INT_MIN;
        for (int i = k; i <= n - 2 * k; ++i) {
            int l = left[i - 1];
            int r = right[i + k];
            int total = (sum[i + k] - sum[i]) + (sum[l + k] - sum[l]) + (sum[r + k] - sum[r]);
            if (total > maxSum) {
                maxSum = total;
                result = {l, i, r};
            }
        }
        return result;
    }
};
