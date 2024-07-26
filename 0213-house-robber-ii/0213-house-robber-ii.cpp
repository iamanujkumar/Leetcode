class Solution {
public:
int fun(vector<int>&nums,int start,int end){
        if (end - start == 1) return nums[start];
        
        int prev2 = nums[start];
        int prev1 = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i < end; i++) {
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
}
    int rob(vector<int>& nums) {
         int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
       int inc = fun(nums,0,nums.size()-1);
       int rej = fun(nums,1,nums.size());
       return max(inc,rej);
    }
};