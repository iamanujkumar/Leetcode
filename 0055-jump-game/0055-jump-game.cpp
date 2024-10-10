class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxi) return false;
            int sum=nums[i]+i;
            maxi=max(maxi,sum);
        }
        return true;
    }
};