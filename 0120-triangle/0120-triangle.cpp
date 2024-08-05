class Solution {
public:

int fun(int m,int n,vector<vector<int>>&triangle,vector<vector<int>>&dp){
    if (m < 0 || n < 0 || n > m) {
            return INT_MAX; // Out of bounds case
        }
    if(m==0 && n==0){
        return triangle[0][0];
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    int up = INT_MAX, left = INT_MAX;
    if(m>0) up = fun(m-1,n,triangle,dp);
    if(n>0) left = fun(m-1,n-1,triangle,dp);

    return dp[m][n] = triangle[m][n]+min(up,left);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        int ans=INT_MAX;
        for(int i=0;i<m;++i){
             ans = min(ans, fun(m-1,i,triangle,dp));
        }
     return ans;   
    }
};