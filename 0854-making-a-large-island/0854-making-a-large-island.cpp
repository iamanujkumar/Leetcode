class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> areaMap;
        int componentId = 2;
        int ans = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        function<int(int, int, int)> dfs = [&](int r, int c, int id) {
            if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 1) return 0;
            grid[r][c] = id;
            int area = 1;
            for (auto [dr, dc] : directions) {
                area += dfs(r + dr, c + dc, id);
            }
            return area;
        };
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    int area = dfs(r, c, componentId);
                    areaMap[componentId++] = area;
                    ans = max(ans, area);
                }
            }
        }
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) {
                    unordered_set<int> seenComponents;
                    int newArea = 1;
                    for (auto [dr, dc] : directions) {
                        int nr = r + dr, nc = c + dc;
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                            int component = grid[nr][nc];
                            if (component > 1 && seenComponents.find(component) == seenComponents.end()) {
                                newArea += areaMap[component];
                                seenComponents.insert(component);
                            }
                        }
                    }

                    ans = max(ans, newArea);
                }
            }
        }
        return ans;
    }
};