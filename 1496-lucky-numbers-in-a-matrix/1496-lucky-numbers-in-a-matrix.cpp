class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;

        // Iterate through each row to find the minimum element in that row
        for (int i = 0; i < m; i++) {
            int minElement = matrix[i][0];
            int minIndex = 0;
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] < minElement) {
                    minElement = matrix[i][j];
                    minIndex = j;
                }
            }

            // Check if this minElement is the maximum in its column
            bool isLucky = true;
            for (int k = 0; k < m; k++) {
                if (matrix[k][minIndex] > minElement) {
                    isLucky = false;
                    break;
                }
            }

            // If it is a lucky number, add it to the result vector
            if (isLucky) {
                result.push_back(minElement);
            }
        }

        return result;
    }
};
