class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long count=0;
        for(int i=0;i<n-1;++i){
            int lb = lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            int ub = upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
            count += (ub - lb);
        }
        return count;
    }
};