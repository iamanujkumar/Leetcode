class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count=0;
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        for(int k=nums.size()-1;k>=2;k--){
            int i=0;
            int j=k-1;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    count+=(j-i);
                    j--;
                }
                else i++;
            }
        }
        return count;
    }
};