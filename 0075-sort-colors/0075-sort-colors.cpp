class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ctn0=0,ctn1=0,ctn2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ctn0++;
            }
            else if(nums[i]==1){
                ctn1++;
            }
            else ctn2++;
        }
        for(int i=0;i<ctn0;i++){
            nums[i]=0;
        }
        for(int i=ctn0;i<ctn0+ctn1;i++){
            nums[i]=1;
        }
        for(int i = ctn0+ctn1;i<nums.size();i++){
            nums[i]=2;
        }
    }
};