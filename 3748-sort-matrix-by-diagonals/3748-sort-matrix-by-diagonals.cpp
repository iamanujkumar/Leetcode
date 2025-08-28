class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> diagMap;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int key = i - j; 
                diagMap[key].push_back(grid[i][j]);
            }
        }
        for (auto &entry : diagMap) {
            int key = entry.first;
            if (key >= 0) {
                sort(entry.second.begin(), entry.second.end(), greater<int>());
            } else {
                sort(entry.second.begin(), entry.second.end());
            }
        }
        unordered_map<int, int> idx; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int key = i - j;
                grid[i][j] = diagMap[key][idx[key]++];
            }
        }
        return grid;
    }
};
