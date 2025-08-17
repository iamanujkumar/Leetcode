class Solution {
public:
    double new21Game(int n, int k, int maxi) {
        if (k == 0 || n >= k + maxi - 1) return 1.0;
        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double sum = 1.0;
        double ans = 0.0;
        for (int i = 1; i <= n; i++) {
            dp[i] = sum / maxi;

            if (i < k) {
                sum += dp[i]; 
            } else {
                ans += dp[i];
            }
            if (i - maxi >= 0) {
                sum -= dp[i - maxi];
            }
        }
        return ans;
    }
};
