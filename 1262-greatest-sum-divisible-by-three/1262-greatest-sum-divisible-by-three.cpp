class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, INT_MIN);
        dp[0] = 0;
        for (int x : nums) {
            vector<int> temp(dp);
            for (int r = 0; r < 3; r++) {
                if (dp[r] != INT_MIN) {
                    int newSum = dp[r] + x;
                    temp[newSum % 3] = max(temp[newSum % 3], newSum);
                }
            }
            dp = temp;
        }
        return dp[0];
    }
};
