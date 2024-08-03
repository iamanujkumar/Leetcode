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
        vector<vector<int>>dp(m,vector<int>(n,0));
        if(obstacleGrid[0][0]==0)dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                   continue;
                }
                else{
                    int up=0,left=0;
                    if(i>0 && obstacleGrid[i][j]==0){
                        up=dp[i-1][j];
                    }
                    if(j>0 && obstacleGrid[i][j]==0){
                        left=dp[i][j-1];
                    }
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};