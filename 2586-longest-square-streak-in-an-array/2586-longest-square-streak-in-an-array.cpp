class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int count=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            long long x=nums[i];
            long long pow = x*x;
            if(binary_search(nums.begin(),nums.end(),pow)){
                int len=1;
                while(binary_search(nums.begin(),nums.end(),pow)){
                    len++;
                    pow=pow*pow;
                }
                count=max(count,len);
            }
        }
        return count;

    }
};