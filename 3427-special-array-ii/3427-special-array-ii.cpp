class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> prefix_sum(n,0);
        prefix_sum[0]=1;
        for(int i=1;i<n;++i){
            if((nums[i]&1) == (nums[i-1]&1))
                prefix_sum[i]=1;
            else prefix_sum[i]=1+prefix_sum[i-1];
        }
        vector<bool> res;
        for(auto& query: queries){
            int start=query[0];
            int end=query[1];
            int size = end-start+1;
            if(prefix_sum[end]>=size) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    
    }
};