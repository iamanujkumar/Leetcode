class Solution {
public:
int fun(vector<int>&nums,int n,vector<int>&dp){
    if(n==0) {
       return nums[n];
    }
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];

   int pick = nums[n] + fun(nums, n - 2,dp);
    int no = fun(nums, n-1,dp);
    return dp[n]=max(pick,no);
}
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return fun(nums,nums.size()-1,dp);
    }
};