#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            adj[i].push_back(i + 1);
        }
        vector<int> vec;
        for (auto& qr : queries) {
            int u = qr[0];
            int v = qr[1];
            adj[u].push_back(v);
            vector<int> dist(n, INT_MAX);
            queue<int> q;
            dist[0] = 0;
            q.push(0);
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int it : adj[curr]) {
                    if (dist[it] > dist[curr] + 1) {
                        dist[it] = dist[curr] + 1;
                        q.push(it);
                    }
                }
            }
            vec.push_back(dist[n - 1]);
        }
        return vec;
    }
};
