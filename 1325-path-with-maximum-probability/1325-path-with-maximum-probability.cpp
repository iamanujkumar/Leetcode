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
            auto [currProb, currNode] = pq.top();
            pq.pop();
            if(currNode == end_node) {
                return currProb;
            }
            for(auto& adj : g[currNode]) {
                int nextNode = adj.first;
                double edgeProb = adj.second;
                if(maxProb[nextNode] < currProb * edgeProb) {
                    maxProb[nextNode] = currProb * edgeProb;
                    pq.push({maxProb[nextNode], nextNode});
                }
            }
        }
        return 0.0;
    }
};