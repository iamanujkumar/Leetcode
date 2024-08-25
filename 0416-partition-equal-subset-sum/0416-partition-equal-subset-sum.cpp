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
    int n = nums.size();
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    if (sum % 2 != 0) return false;

    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : nums) {
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    return dp[target];
}

};