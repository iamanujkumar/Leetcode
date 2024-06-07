class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=nums[i];

            if(ans>maxi){
                maxi=ans;
            }
            if(ans<0){
                ans=0;
            }
        }
        return maxi;
    }
};