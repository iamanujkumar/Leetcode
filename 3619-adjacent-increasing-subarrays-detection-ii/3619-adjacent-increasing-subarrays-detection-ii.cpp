class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int curr=1;
        int prev=0;
        int k=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                curr++;
            }
            else{
                prev=curr;
                curr=1;
            }
            k=max(k,curr/2);
            k=max(k,min(curr,prev));
        }
        return k;
    }
};