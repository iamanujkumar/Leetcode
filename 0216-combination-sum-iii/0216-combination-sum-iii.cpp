class Solution {
public:
    void fun(vector<int> nums, int k, int i, vector<vector<int>>& ans, vector<int> v, int n) {
        if (v.size() == k) {
            if (n == 0) {
                ans.push_back(v);
            }
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] > n) break;
            v.push_back(nums[j]);
            fun(nums, k, j + 1, ans, v, n - nums[j]);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> nums;
        for (int i = 1; i <= 9; i++) {
            nums.push_back(i);
        }
        vector<int> v;
        fun(nums, k, 0, ans, v, n);
        return ans;
    }
};
