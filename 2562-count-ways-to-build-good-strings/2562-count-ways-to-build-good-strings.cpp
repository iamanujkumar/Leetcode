class Solution {
public:
int mod=1000000007;
int count(int low,int high,int zero,int one,int len,vector<int>& dp){
    if(len>high) return 0;
    if (dp[len] != -1) return dp[len];
    int ans = 0;
    ans = (ans + count(low, high, zero, one, len + zero, dp)) % mod;
    ans = (ans + count(low, high, zero, one, len + one, dp)) % mod;
    if(len>=low && len<=high) ans++;
    return dp[len] = ans;

}
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return count(low,high,zero,one,0,dp);
    }
};