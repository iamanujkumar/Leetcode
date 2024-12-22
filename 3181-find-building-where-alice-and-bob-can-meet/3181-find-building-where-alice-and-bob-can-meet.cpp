class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& queries) {
        int n = h.size(), m = queries.size();
        vector<int> val(m, -1);
        unordered_map<int, vector<pair<int, int>>> mp;       
        for(int id=0;id<m;id++){
            auto qry = queries[id];
            int i = qry[0], j = qry[1];
            if(i<j && h[i] < h[j]){
                val[id] = j;
            }else if(i>j && h[i] > h[j]){
                val[id] = i;
            }else if(i==j){
                val[id] = i;
            }else{
                mp[max(i, j)].push_back({ max(h[i], h[j]) , id});
            }
        }       
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int id=0;id<n;id++){
            int curh = h[id];
            while(!pq.empty() && pq.top().first < curh){
                val[pq.top().second] = id;
                pq.pop();
            }  
            for(auto p : mp[id]){
                pq.push(p);
            }
        }
        return val;
    }
};