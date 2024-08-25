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
            vector<vector<int>>dp(n+1,vector<int>((sum/2)+1,-1));
            return fun(n,sum/2,nums,dp);
        }
        
    }
};