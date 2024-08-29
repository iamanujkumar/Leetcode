#include <vector>
#include <unordered_map>
using namespace std;

class UnionFind {
public:
    UnionFind(int size) {
        pr.resize(size);
        for (int i = 0; i < size; ++i) {
            pr[i] = i;
        }
    }

    int find(int x) {
        if (pr[x] != x) {
            pr[x] = find(pr[x]);
        }
        return pr[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            pr[rootY] = rootX;
        }
    }

private:
    vector<int> pr;
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind ans(2 * n);
        
        unordered_map<int, int> rowMap;
        unordered_map<int, int> colMap;
        int rowId = 0;
        int colId = 0;
        unordered_map<int, int> rowToId;
        unordered_map<int, int> colToId;

        for (const auto& stone : stones) {
            int row = stone[0];
            int col = stone[1];
            if (rowToId.find(row) == rowToId.end()) {
                rowToId[row] = rowId++;
            }
            if (colToId.find(col) == colToId.end()) {
                colToId[col] = colId++;
            }

            ans.unionSets(rowToId[row], colToId[col] + n);
        }
        unordered_map<int, int> cnt;
        int numComponents = 0;
        for (const auto& [row, id] : rowToId) {
            int root = ans.find(id);
            if (cnt.find(root) == cnt.end()) {
                ++numComponents;
                cnt[root] = 1;
            }
        }
        
        return n - numComponents;
    }
};
