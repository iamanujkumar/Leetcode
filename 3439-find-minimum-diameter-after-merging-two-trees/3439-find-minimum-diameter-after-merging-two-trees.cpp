class Solution {
public:
    pair<int, int> bfs(int start, const vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        int farthestNode = start;
        int maxDist = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : graph[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    if (dist[neighbor] > maxDist) {
                        maxDist = dist[neighbor];
                        farthestNode = neighbor;
                    }
                }
            }
        }

        return {farthestNode, maxDist};
    }
    int calculateDiameter(const vector<vector<int>>& edges, int n) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        auto [farthestNode, _] = bfs(0, graph);
        auto [_, diameter] = bfs(farthestNode, graph);
        return diameter;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;
        int dm1 = calculateDiameter(edges1, n1);
        int dm2 = calculateDiameter(edges2, n2);
        int result = max({dm1, dm2, (dm1 + 1) / 2 + (dm2 + 1) / 2 + 1});
        return result;
    }
};
