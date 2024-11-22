class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternCount;
        int ans = 0;
        for (auto& row : matrix) {
            string pattern;
            for (int cell : row) {
                pattern += (cell == row[0] ? '0' : '1');
            }
            patternCount[pattern]++;
            ans = max(ans, patternCount[pattern]);
        }
        return ans;
    }
};