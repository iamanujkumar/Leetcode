class Solution {
public:
    bool fun(vector<int>& arr, int n, int sum, vector<vector<int>>& dp) {
    if (sum == 0) return true;
    if (n == 0) return false;
    if (dp[n][sum] != -1) return dp[n][sum];
    if (arr[n - 1] > sum)
        return dp[n][sum] = fun(arr, n - 1, sum, dp);
    return dp[n][sum] = fun(arr, n - 1, sum, dp) ||
                        fun(arr, n - 1, sum - arr[n - 1], dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        else{
            vector<vector<int>>dp(n+1,vector<int>(sum/2+1, -1));
            return fun(nums,n,sum/2,dp);
        }
    }
};