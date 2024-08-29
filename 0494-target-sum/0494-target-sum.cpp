class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // Check if the problem is feasible
        if (sum < abs(target) || (sum + target) % 2 != 0) {
            return 0;
        }

        int val = (sum + target) / 2;

        // If val is negative or too large, return 0
        if (val < 0 || val > sum) {
            return 0;
        }

        vector<vector<int>> dp(n + 1, vector<int>(val + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= val; j++) {
                if (nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][val];
    }
};
