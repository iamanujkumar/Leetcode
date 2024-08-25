class Solution {
public:
bool fun(int n,int w,vector<int>& nums, vector<vector<int>>&dp){
    if(w==0) return true;
    if(n==0) return false;
    if(dp[n][w]!=-1) return dp[n][w];
    if(nums[n-1]<=w){
        return dp[n][w]= fun(n-1,w-nums[n-1],nums,dp) || fun(n-1,w,nums,dp);
    }
    else return dp[n][w] = fun(n-1,w,nums,dp);
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        else{
            vector<vector<bool>>dp(n+1,vector<bool>((sum/2)+1,false));
            for(int i=0;i<=n;i++){
                dp[i][0] = true;
            }

            for(int i=1;i<=n;i++){
                for(int j=1;j<=sum/2;j++){
                    if(nums[i-1]<=j){
                        dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j]; 
                    }
                    else dp[i][j] = dp[i-1][j];
                }
            }
            return dp[n][sum/2];
        }
        
    }
};