class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pt1=0,pt2=0,pt3=nums.size()-1;
        while(pt2<=pt3){
            if(nums[pt2]==0){
                swap(nums[pt1],nums[pt2]);
                pt1++;
                pt2++;
            }
            else if(nums[pt2]==1){
                pt2++;
            }
            else{
                swap(nums[pt2],nums[pt3]);
                pt3--;
            }
        }
    }
};