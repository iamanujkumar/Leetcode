class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int mini = INT_MAX;
        int cnt = 0;
        for (const auto& row : matrix) {
            for (int it : row) {
                totalSum += abs(it);
                mini = min(mini, abs(it));
                if (it < 0) {
                    cnt++;
                }
            }
        }
        if (cnt % 2 != 0) {
            totalSum -= 2 * mini;
        }
        return totalSum;
    }
};
