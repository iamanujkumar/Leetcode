class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int maxi=1;
        int ans=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i]==nums[i-1]+1){
                ans+=1;
            }
            else {
                maxi=max(maxi,ans);
                ans=1;
            }

            }
        }
        return max(maxi,ans);
    }
};