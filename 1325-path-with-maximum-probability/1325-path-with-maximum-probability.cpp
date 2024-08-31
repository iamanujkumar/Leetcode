class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> g(n);
        for(int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;
        
        while(!pq.empty()) {
            auto [currProb, nNode] = pq.top();
            pq.pop();
            if(nNode == end_node) {
                return currProb;
            }
            for(auto& adj : g[nNode]) {
                int nextNode = adj.first;
                double edg = adj.second;
                if(maxProb[nextNode] < currProb * edg) {
                    maxProb[nextNode] = currProb * edg;
                    pq.push({maxProb[nextNode], nextNode});
                }
            }
        }
        return 0.0;
    }
};
