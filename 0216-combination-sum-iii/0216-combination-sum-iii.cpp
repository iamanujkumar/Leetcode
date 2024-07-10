class Solution {
public:
    void fun(int k, int start, vector<vector<int>>& ans, vector<int> v, int n) {
        if (v.size() == k && n == 0) {
            ans.push_back(v);
            return;
        }
       
        for (int i = start; i <= 9; i++) {
            v.push_back(i);
            fun(k, i + 1, ans, v, n - i);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        fun(k, 1, ans, v, n);
        return ans;
    }
};
