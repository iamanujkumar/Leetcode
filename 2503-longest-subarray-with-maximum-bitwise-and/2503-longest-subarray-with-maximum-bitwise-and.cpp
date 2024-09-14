class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int count=1;
        int res=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1] && nums[i]==maxi){
                count++;
                res=max(res,count);
            }
            else count=1;
        }
        return res;
    }
};