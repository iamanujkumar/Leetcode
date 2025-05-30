class Solution {
public:
    vector<int> getDistances(vector<int>& edges, int start) {
        int n = edges.size();
        vector<int> dist(n, -1);
        int curr = start, d = 0;
        while (curr != -1 && dist[curr] == -1) {
            dist[curr] = d++;
            curr = edges[curr];
        }
        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1 = getDistances(edges, node1);
        vector<int> dist2 = getDistances(edges, node2);
        int answer = -1;
        int minDist = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    answer = i;
                }
            }
        }
        return answer;
    }
};
