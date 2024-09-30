class Solution {
public:
int solve(vector<int>& values, int i, int j, vector<vector<int>>& dp) {
    if (i >= j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    
    int mini = INT_MAX;
    
    for (int k = i; k <= j - 1; k++) {
        int temp = solve(values, i, k, dp) + solve(values, k + 1, j, dp) + values[i - 1] * values[k] * values[j];
        if (temp < mini) mini = temp;
    }
    
    return dp[i][j] = mini;
}
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(values.size(), vector<int>(values.size(), -1));
        return solve(values, 1, values.size() - 1, dp);
    }
};