class Solution {
public:
int fun(int m,int n,vector<vector<int>>&dp){
    if (m < 0 || n < 0) return 0;
    if (m == 0 && n == 0) return 1;
    if(dp[m][n]!=-1) return dp[m][n];
    int up = fun(m-1,n,dp);
    int left=fun(m,n-1,dp);
    return dp[m][n]= up+left;

}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(m-1,n-1,dp);
    }
};