class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> vec2(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int nbh : graph[i]) {
                reverseGraph[nbh].push_back(i);
                vec2[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (vec2[i] == 0) q.push(i); 
        }
        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (int nbh : reverseGraph[node]) {
                vec2[nbh]--;
                if (vec2[nbh] == 0) {
                    q.push(nbh);
                }
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
