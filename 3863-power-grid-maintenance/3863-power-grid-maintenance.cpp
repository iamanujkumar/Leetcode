class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        for (auto &e : connections) dsu.unite(e[0], e[1]);
        unordered_map<int, set<int>> compSet;
        for (int i = 1; i <= c; i++) {
            int root = dsu.find(i);
            compSet[root].insert(i);
        }
        vector<bool> online(c + 1, true);
        vector<int> ans;
        for (auto &q : queries) {
            int type = q[0], x = q[1];
            int root = dsu.find(x);
            if (type == 1) {
                if (online[x]) ans.push_back(x);
                else {
                    if (compSet[root].empty()) ans.push_back(-1);
                    else ans.push_back(*compSet[root].begin());
                }
            } else if (type == 2) {
                if (online[x]) {
                    online[x] = false;
                    compSet[root].erase(x);
                }
            }
        }
        return ans;
    }
};
