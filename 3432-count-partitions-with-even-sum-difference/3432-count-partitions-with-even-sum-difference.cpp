class Solution {
public:
    bool isEven(int val){
        return val%2==0;
    }
    int countPartitions(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int count=0;
        int prevSum=0;
        for(int i=0;i<nums.size()-1;i++){
            prevSum+=nums[i];
            if(isEven(prevSum-(sum-prevSum))) count++;
        }
        return count;
    }
};