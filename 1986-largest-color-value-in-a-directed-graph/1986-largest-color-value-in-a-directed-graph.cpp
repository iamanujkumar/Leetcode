class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        vector<vector<int>> dp(n, vector<int>(26, 0));
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0;
        int maxColorVal = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited++;
            dp[node][colors[node] - 'a']++;
            for (int nei : graph[node]) {
                for (int c = 0; c < 26; ++c) {
                    dp[nei][c] = max(dp[nei][c], dp[node][c]);
                }
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
            maxColorVal = max(maxColorVal, *max_element(dp[node].begin(), dp[node].end()));
        }
        return (visited == n) ? maxColorVal : -1;
    }
};
