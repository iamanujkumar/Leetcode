class Solution {
    #define pii pair<int,int>
    int BFS(int start,vector<vector<int>>& adj,int k){
        queue<pii> q;
        q.push(make_pair(start,-1));
        int count = 0;
        while(!q.empty() and k>=0){
            int size=q.size();
            count += size;
            for(int i=0;i<size;++i){
                pii curr = q.front();
                q.pop();
                int u = curr.first;
                int parent = curr.second;
                for(int v: adj[u]){
                    if(v!=parent){
                        q.push(make_pair(v,u));
                    }
                }
            }
            k--;
        }
        return count;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int m = edges1.size()+1;
        int n = edges2.size()+1;
        vector<vector<int>> adj1(m),adj2(n);
        for(auto& edge: edges1){
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for(auto& edge: edges2){
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }
        //Preprocess: Find the best node in Tree-2
        int best=0;
        for(int i=0;i<n;++i){
            int connections = BFS(i,adj2,k-1);
            best = max(best,connections);
        }
        
        //Build answer
        vector<int> res(m);
        for(int i=0;i<m;++i){
            int connections = BFS(i,adj1,k);
            res[i] = connections + best;
        }
        return res;
    }
};