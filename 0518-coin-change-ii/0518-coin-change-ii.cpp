class Solution {
public:

int fun(int n,int k,vector<int>&v,vector<vector<int>>&dp){
    if(n==0) return 0;
    if(k==0) return 1;
    if(dp[n][k]!=-1) return dp[n][k];
    if(v[n-1]<=k){
        return dp[n][k] = fun(n,k-v[n-1],v,dp) + fun(n-1,k,v,dp);
    }
    else return dp[n][k] = fun(n-1,k,v,dp);
}
    int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (coins[i - 1] <= j)
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][amount];
}
};