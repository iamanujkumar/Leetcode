class Solution {
public:
    int n, m;
    vector<vector<int>> g;
    int dx[4] = {1, 1, -1, -1};
    int dy[4] = {1, -1, -1, 1};
    int turn[4] = {1, 2, 3, 0}; 
    bool valid(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    int expectedVal(int k) {
        if (k == 0) return 1;
        return (k % 2 ? 2 : 0);
    }
    int dfs(int x, int y, int d, int t, int k, vector<vector<vector<vector<int>>>> &dp) {
        if (!valid(x, y)) return 0;
        if (g[x][y] != expectedVal(k)) return 0;
        int &res = dp[x][y][d][t];
        if (res != -1) return res;
        res = 1;
        int nx = x + dx[d], ny = y + dy[d];
        res = max(res, 1 + dfs(nx, ny, d, t, k+1, dp));
        if (!t) {
            int nd = turn[d];
            int tx = x + dx[nd], ty = y + dy[nd];
            res = max(res, 1 + dfs(tx, ty, nd, 1, k+1, dp));
        }
        return res;
    } 
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        g = grid;
        n = g.size();
        m = g[0].size();
        int ans = 0;
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(2, -1))));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        ans = max(ans, dfs(i, j, d, 0, 0, dp));
                    }
                }
            }
        }
        return ans;
    }
};
