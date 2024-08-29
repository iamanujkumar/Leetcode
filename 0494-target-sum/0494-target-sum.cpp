class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        // If (target + sum) is odd or target + sum < 0, return 0
        if ((target + sum) % 2 != 0 || (target + sum) < 0) {
            return 0;
        }

        int s = (target + sum) / 2;
        int n = nums.size();

        // DP array to store the number of subsets that sum to a given value
        vector<int> dp(s + 1, 0);
        dp[0] = 1;  // There's one way to have a sum of 0: use no elements.

        for (int num : nums) {
            for (int j = s; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }

        return dp[s];
    }
};
