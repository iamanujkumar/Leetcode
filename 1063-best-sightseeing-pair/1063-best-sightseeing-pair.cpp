class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int maxI = values[0];
        for (int j = 1; j < values.size(); ++j) {
            maxScore = max(maxScore, maxI + values[j] - j);
            maxI = max(maxI, values[j] + j);
        }
        return maxScore;
    }
};
