class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int totalCells = rows * cols;
        int steps = 0;
        int directionIndex = 0;
        int r = rStart, c = cStart;

        result.push_back({r, c});
        if (totalCells == 1) return result;  // Edge case for 1x1 grid

        while (result.size() < totalCells) {
            if (directionIndex == 0 || directionIndex == 2) steps++;  // Increase step count after horizontal moves
            for (int i = 0; i < steps; ++i) {
                r += directions[directionIndex].first;
                c += directions[directionIndex].second;

                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    result.push_back({r, c});
                    if (result.size() == totalCells) return result;
                }
            }
            directionIndex = (directionIndex + 1) % 4;  // Cycle through directions
        }

        return result;
    }
};
