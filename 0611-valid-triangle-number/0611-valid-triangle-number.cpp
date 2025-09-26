class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count=0;
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                if(nums[i]!=0 && nums[j]!=0){
                    int sum = nums[i]+nums[j];
                    for(int k=j+1;k<nums.size();k++){
                       if(sum>nums[k]) count++;
                    }
                }
            }
        }
        return count;
    }
};