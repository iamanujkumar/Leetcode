class Solution {
public:
    int missingNumber(vector<int>& nums) {
     int sum1=0,sum2=0;
     for(int i=0;i<=nums.size();i++){
        sum1+=i;
     }  
     for(int i=0;i<nums.size();i++){
        sum2+=nums[i];
     }  
     return sum1-sum2;
    }
};