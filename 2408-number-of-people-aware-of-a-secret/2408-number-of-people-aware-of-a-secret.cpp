class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1), share(n + 2);
        dp[1] = 1;
        share[1 + delay] += 1;  
        share[1 + forget] -= 1; 
        long long currShare = 0;
        for (int day = 2; day <= n; day++) {
            currShare = (currShare + share[day]) % MOD; 
            if (currShare < 0) currShare += MOD;    
            dp[day] = currShare; 
            if (day + delay <= n) {
                share[day + delay] = (share[day + delay] + dp[day]) % MOD;
            }
            if (day + forget <= n) {
                share[day + forget] = (share[day + forget] - dp[day]) % MOD;
            }
        }
        long long ans = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            if (day >= 1) {
                ans = (ans + dp[day]) % MOD;
            }
        }
        return (int)ans;
    }
};
