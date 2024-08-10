#include <vector>
#include <string>

class UnionFind {
public:
    std::vector<int> parent, rank;
    
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution {
public:
    int regionsBySlashes(std::vector<std::string>& grid) {
        int n = grid.size();
        int total = n * n * 4; // Total number of triangles
        UnionFind uf(total);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int root = (i * n + j) * 4;
                
                char val = grid[i][j];
                if (val == '/') {
                    uf.unionSet(root + 0, root + 3);
                    uf.unionSet(root + 1, root + 2);
                } else if (val == '\\') {
                    uf.unionSet(root + 0, root + 1);
                    uf.unionSet(root + 2, root + 3);
                } else {
                    uf.unionSet(root + 0, root + 1);
                    uf.unionSet(root + 1, root + 2);
                    uf.unionSet(root + 2, root + 3);
                }
                
                // Connect to the neighboring cells
                if (i > 0) {
                    uf.unionSet(root + 0, ((i - 1) * n + j) * 4 + 2);
                }
                if (j > 0) {
                    uf.unionSet(root + 3, (i * n + (j - 1)) * 4 + 1);
                }
            }
        }
        
        int regions = 0;
        for (int i = 0; i < total; i++) {
            if (uf.find(i) == i) {
                regions++;
            }
        }
        
        return regions;
    }
};
