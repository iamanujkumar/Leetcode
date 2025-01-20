class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // Step 1: Preprocess the positions of each element in the matrix.
        unordered_map<int, pair<int, int>> position_map;  // value -> (row, col)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                position_map[mat[i][j]] = {i, j};
            }
        }

        // Step 2: Initialize row and column count arrays.
        vector<int> row_count(m, 0);
        vector<int> col_count(n, 0);

        // Step 3: Iterate through arr and update row and column counts.
        for (int i = 0; i < arr.size(); ++i) {
            int num = arr[i];
            auto [row, col] = position_map[num];

            // Increment the counts for the row and column.
            row_count[row]++;
            col_count[col]++;

            // Check if any row or column is fully painted.
            if (row_count[row] == n || col_count[col] == m) {
                return i;
            }
        }

        return -1;  // In case no row or column is fully painted.
    }
};
