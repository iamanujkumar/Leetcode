class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>v;
        long long current = 0;
        for(int i=0;i<nums.size();i++){
            current = (current*2+nums[i])%5;
            if(current==0) v.push_back(true);
            else v.push_back(false);
        }
        return v;
    }
};