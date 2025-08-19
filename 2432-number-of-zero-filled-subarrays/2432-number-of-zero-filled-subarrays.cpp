class Solution {
public:
    long long fun(long long n){
        long long val=0;
        for(long long i=1;i<=n;i++){
            val+=i;
        }
        return val;
    }

    long long zeroFilledSubarray(vector<int>& nums) {
        long long i=0;
        long long ans=0;
        while(i<nums.size()){
            long long count=0;
            if(nums[i]==0){
                while(i<nums.size() && nums[i] == 0){
                    count++;
                    i++;
                }
                ans+=(count*(count+1))/2;
            }
            i++;
        }
        return ans;
    }
};