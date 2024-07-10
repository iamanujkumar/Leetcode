class Solution {
public:
void fun(vector<int>nums, int n,int i,vector<int>v,vector<vector<int>>&ans){
      if(i==n){
          ans.push_back(v);
          return;
      }
      v.push_back(nums[i]);
      fun(nums,n,i+1,v,ans);
      v.pop_back();
      while (i + 1 < n && nums[i] == nums[i + 1]) i++;
        fun(nums, n, i + 1, v, ans);
      
  }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>v;
        fun(nums,nums.size(),0,v,ans);
        return ans;
    }
};