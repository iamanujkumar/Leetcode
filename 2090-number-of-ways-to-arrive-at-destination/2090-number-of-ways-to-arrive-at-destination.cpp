class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            if (time > dist[node]) continue;
            for (auto [nextNode, travelTime] : adj[node]) {
                long long newTime = time + travelTime;
                if (newTime < dist[nextNode]) {
                    dist[nextNode] = newTime;
                    ways[nextNode] = ways[node];
                    pq.push({newTime, nextNode});
                }
                else if (newTime == dist[nextNode]) {
                    ways[nextNode] = (ways[nextNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};
