class Solution {
public:
int fun(vector<int>&v){
    int n=v.size();
    int prev2=0;
    int prev1=v[0];
    for(int i=1;i<n;i++){
        int incl = prev2+v[i];
        int exc = prev1+0;
        int ans = max(incl,exc);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        return fun(nums);
    }
};