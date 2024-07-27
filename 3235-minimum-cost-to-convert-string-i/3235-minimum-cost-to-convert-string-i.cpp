class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
          int n = source.size();
        int INF = INT_MAX;
        unordered_map<char, unordered_map<char, int>> transformationCost;

        // Initialize all transformation costs to infinity
        for (char c = 'a'; c <= 'z'; ++c) {
            for (char d = 'a'; d <= 'z'; ++d) {
                transformationCost[c][d] = (c == d) ? 0 : INF;
            }
        }

        // Fill the transformation cost map with the given costs
        for (int i = 0; i < original.size(); ++i) {
            char from = original[i];
            char to = changed[i];
            int c = cost[i];
            transformationCost[from][to] = min(transformationCost[from][to], c);
        }

        // Function to perform Dijkstra's algorithm
        auto dijkstra = [&](char start) {
            vector<int> dist(26, INF);
            priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
            dist[start - 'a'] = 0;
            pq.push({0, start});
            
            while (!pq.empty()) {
                auto [currentDist, u] = pq.top();
                pq.pop();
                
                if (currentDist > dist[u - 'a']) continue;
                
                for (char v = 'a'; v <= 'z'; ++v) {
                    if (dist[u - 'a'] != INF && transformationCost[u][v] != INF) {
                        int newDist = dist[u - 'a'] + transformationCost[u][v];
                        if (newDist < dist[v - 'a']) {
                            dist[v - 'a'] = newDist;
                            pq.push({newDist, v});
                        }
                    }
                }
            }
            
            return dist;
        };

        // Compute shortest path costs for all characters using Dijkstra
        unordered_map<char, vector<int>> shortestPaths;
        for (char c = 'a'; c <= 'z'; ++c) {
            shortestPaths[c] = dijkstra(c);
        }

        long long totalCost = 0;

        // Calculate the minimum cost to convert source to target
        for (int i = 0; i < n; ++i) {
            char from = source[i];
            char to = target[i];

            if (shortestPaths[from][to - 'a'] == INF) {
                return -1;  // Transformation not possible
            } else {
                totalCost += shortestPaths[from][to - 'a'];
            }
        }

        return totalCost;
    }
};