class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
    double maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                auto& p1 = points[i];
                auto& p2 = points[j];
                auto& p3 = points[k];
                double area = 0.5 * abs(
                    p1[0] * (p2[1] - p3[1]) + 
                    p2[0] * (p3[1] - p1[1]) + 
                    p3[0] * (p1[1] - p2[1])
                );

                maxArea = max(maxArea, area);
            }
        }
    }
    return maxArea;
    }
};