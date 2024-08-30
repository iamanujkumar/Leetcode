class Solution {
public:
    typedef long long ll;
    const int lg = 2e9;
    typedef pair<long, long> P;

    ll dkl(vector<vector<int>>& edges, int n, int src, int dest) {
        unordered_map<ll, vector<pair<ll, ll>>> adj;
        for(vector<int>& edge : edges) {
            if(edge[2] != -1) {
                int u  = edge[0];
                int v  = edge[1];
                int wt = edge[2];

                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<ll> ans(n, INT_MAX);
        vector<bool> visited(n, false);

        ans[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            ll currDist = pq.top().first;
            ll currNode = pq.top().second;
            pq.pop();

            if(visited[currNode] == true) {
                continue;
            }
            visited[currNode] = true;

            for(auto&[nbr, wt] : adj[currNode]) {
                if(ans[nbr] > currDist + wt) {
                    ans[nbr] = currDist + wt;
                    pq.push({ans[nbr], nbr});
                }
            }
        }

        return ans[dest];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll currShortestDist = dkl(edges, n, source, destination);

        if(currShortestDist < target) {
            return {};
        }

        bool mtch = (currShortestDist == target);

        for(vector<int>& edge : edges) {
            if(edge[2] == -1) {

                edge[2] = (mtch == true) ? lg : 1;

                if(mtch != true) {
                    ll newShortestDist = dkl(edges, n, source, destination);

                    if(newShortestDist <= target) {
                        mtch = true;
                        edge[2] += (target - newShortestDist);
                    }
                }
            }
        }

        if(mtch == false) {
            return {};
        }
        return edges;
    }
};