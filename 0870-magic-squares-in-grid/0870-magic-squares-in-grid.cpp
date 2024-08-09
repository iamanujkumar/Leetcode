class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c) {
        vector<bool> visited(10, false); // To track numbers from 1 to 9
        int sum = 0;

        // Check rows and mark visited numbers
        for (int i = 0; i < 3; ++i) {
            int rowSum = 0;
            for (int j = 0; j < 3; ++j) {
                int val = grid[r + i][c + j];
                if (val < 1 || val > 9 || visited[val]) return false;
                visited[val] = true;
                rowSum += val;
            }
            if (i == 0) sum = rowSum;  // Set initial row sum
            else if (sum != rowSum) return false;  // Compare with other rows
        }

        // Check columns
        for (int j = 0; j < 3; ++j) {
            int colSum = 0;
            for (int i = 0; i < 3; ++i) {
                colSum += grid[r + i][c + j];
            }
            if (sum != colSum) return false;
        }

        // Check diagonals
        int diagSum1 = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
        int diagSum2 = grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c];

        if (sum != diagSum1 || sum != diagSum2) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        // Traverse each 3x3 subgrid
        for (int i = 0; i <= rows - 3; ++i) {
            for (int j = 0; j <= cols - 3; ++j) {
                if (isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};
