class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
         int n = source.size();
        int INF = INT_MAX;
        unordered_map<char, unordered_map<char, int>> transformationCost;
        for (char c = 'a'; c <= 'z'; ++c) {
            for (char d = 'a'; d <= 'z'; ++d) {
                if (c == d) {
                    transformationCost[c][d] = 0; 
                } else {
                    transformationCost[c][d] = INF;
                }
            }
        }
        for (int i = 0; i < original.size(); ++i) {
            char from = original[i];
            char to = changed[i];
            int c = cost[i];
            transformationCost[from][to] = min(transformationCost[from][to], c);
        }
        for (char k = 'a'; k <= 'z'; ++k) {
            for (char i = 'a'; i <= 'z'; ++i) {
                for (char j = 'a'; j <= 'z'; ++j) {
                    if (transformationCost[i][k] < INF && transformationCost[k][j] < INF) {
                        transformationCost[i][j] = min(transformationCost[i][j], transformationCost[i][k] + transformationCost[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;

        for (int i = 0; i < n; ++i) {
            char from = source[i];
            char to = target[i];

            if (transformationCost[from][to] == INF) {
                return -1; 
            } else {
                totalCost += transformationCost[from][to];
            }
        }

        return totalCost;
    }
};