class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> tree(n);
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        vector<int> xorSubtree(n);
        vector<int> tin(n), tout(n);
        int time = 0;

        function<void(int, int)> dfs = [&](int node, int parent) {
            tin[node] = time++;
            xorSubtree[node] = nums[node];
            for (int nei : tree[node]) {
                if (nei == parent) continue;
                dfs(nei, node);
                xorSubtree[node] ^= xorSubtree[nei];
            }
            tout[node] = time++;
        };

        dfs(0, -1);
        int totalXOR = xorSubtree[0];
        int res = INT_MAX;

        // Check if u is ancestor of v
        auto isAncestor = [&](int u, int v) {
            return tin[u] < tin[v] && tout[v] < tout[u];
        };

        // Try all pairs of nodes u, v (representing removed edges to their parents)
        for (int u = 1; u < n; ++u) {
            for (int v = u + 1; v < n; ++v) {
                int x, y, z;
                if (isAncestor(u, v)) {
                    x = xorSubtree[v];
                    y = xorSubtree[u] ^ xorSubtree[v];
                    z = totalXOR ^ xorSubtree[u];
                } else if (isAncestor(v, u)) {
                    x = xorSubtree[u];
                    y = xorSubtree[v] ^ xorSubtree[u];
                    z = totalXOR ^ xorSubtree[v];
                } else {
                    x = xorSubtree[u];
                    y = xorSubtree[v];
                    z = totalXOR ^ x ^ y;
                }
                int maxi = max({x, y, z});
                int mini = min({x, y, z});
                res = min(res, maxi - mini);
            }
        }
        return res;
    }
};
