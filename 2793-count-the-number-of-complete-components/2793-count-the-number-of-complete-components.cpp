class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        function<void(int, vector<int>&)> dfs = [&](int node, vector<int>& component) {
            visited[node] = true;
            component.push_back(node);
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor, component);
                }
            }
        };
        int completeComponents = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, component);
                int size = component.size();
                int expectedEdges = (size * (size - 1)) / 2;
                int actualEdges = 0;

                for (int node : component) {
                    actualEdges += adj[node].size();
                }
                actualEdges /= 2;
                if (actualEdges == expectedEdges) {
                    completeComponents++;
                }
            }
        }
        return completeComponents;
    }
};