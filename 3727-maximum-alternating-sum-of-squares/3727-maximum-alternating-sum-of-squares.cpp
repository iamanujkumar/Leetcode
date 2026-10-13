class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        sort(nums.begin(), nums.end(), [](int a,int b){
            return abs(a)<abs(b);
        });
        int left=0,right=0;
        for(int i=n/2;i<n;i++){
            long long x=nums[i];
            ans+=x*x;
        }
        for(int i=0;i<n/2;i++){
            long long x=nums[i];
            ans-=x*x;
        }
        return ans;
    }
};