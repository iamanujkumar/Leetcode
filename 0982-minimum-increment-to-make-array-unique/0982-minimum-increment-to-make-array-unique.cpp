class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                int val=nums[i-1]+1;
                count+=val-nums[i];
                nums[i]=val;

            }
        }
        return count;

    }
};