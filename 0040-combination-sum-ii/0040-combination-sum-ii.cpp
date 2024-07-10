class Solution {
public:
    void fun(vector<int>& candidates, int n, int i, vector<vector<int>>& ans, vector<int>& v, int target) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        for (int j = i; j < n; ++j) {
            if (j > i && candidates[j] == candidates[j - 1]) continue;
            if (candidates[j] > target) break;
            v.push_back(candidates[j]);
            fun(candidates, n, j + 1, ans, v, target - candidates[j]);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        fun(candidates, candidates.size(), 0, ans, v, target);
        return ans;
    }
};
