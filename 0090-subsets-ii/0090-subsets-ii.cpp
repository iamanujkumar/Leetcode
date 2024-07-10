class Solution {
public:
    void fun(vector<int>& nums, int i, vector<int>& v, vector<vector<int>>& ans) {
        ans.push_back(v);
        for (int j = i; j < nums.size(); ++j) {
            if (j > i && nums[j] == nums[j - 1]) continue; // skip duplicates
            v.push_back(nums[j]);
            fun(nums, j + 1, v, ans);
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        fun(nums, 0, v, ans);
        return ans;
    }
};
