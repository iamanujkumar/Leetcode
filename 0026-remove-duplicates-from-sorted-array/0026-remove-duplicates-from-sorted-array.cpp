class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1;
        int val=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=val){
                nums[count]=nums[i];
                count++;
                
            }
            val=nums[i];
        }
        return count;
    }
};