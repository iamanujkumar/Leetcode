class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> fsa(m, 0);
        vector<int> fa(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    fsa[i]++;
                    fa[j]++;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (fsa[i] > 1 || fa[j] > 1) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};
