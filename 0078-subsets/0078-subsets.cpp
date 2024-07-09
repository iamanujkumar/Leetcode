class Solution {
public:

void fun(vector<vector<int>>&ans, int n,int i,vector<int>v,vector<int>nums){
    if(i==n){
        ans.push_back(v);
        return;
    }
    v.push_back(nums[i]);
    fun(ans,n,i+1,v,nums);
    v.pop_back();
    fun(ans,n,i+1,v,nums);
    return;   

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        fun(ans,nums.size(),0,v,nums);
        return ans;
    }
};