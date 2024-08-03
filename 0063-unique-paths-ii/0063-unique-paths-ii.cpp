class Solution {
public:
int fun(int m,int n,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){
    if (m < 0 || n < 0 || obstacleGrid[m][n]==1) return 0;
    if (m == 0 && n == 0) return 1;
    if(dp[m][n]!=-1) return dp[m][n];
    int up = fun(m-1,n,dp,obstacleGrid);
    int left=fun(m,n-1,dp,obstacleGrid);
    return dp[m][n]= up+left;

}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(m-1,n-1,dp,obstacleGrid);
    }
};