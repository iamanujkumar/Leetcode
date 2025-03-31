class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0; 
        vector<int> partitionValues;
        for (int i = 0; i < n - 1; i++) {
            partitionValues.push_back(weights[i] + weights[i + 1]);
        }
        sort(partitionValues.begin(), partitionValues.end());
        long long mini = 0, maxScore = 0;
        for (int i = 0; i < k - 1; i++) {
            mini += partitionValues[i];
            maxScore += partitionValues[n - 2 - i];
        }
        return maxScore - mini;
    }
};
