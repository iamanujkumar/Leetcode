/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
      unordered_map<int, int> mhp;
    unordered_map<int, int> depthMap;
    unordered_map<int, vector<int>> dpth;
    int dfs(TreeNode* node, int depth) {
        if (!node) return -1;
        int lh = dfs(node->left, depth + 1);
        int rh = dfs(node->right, depth + 1);
        int ndh = max(lh, rh) + 1;
        mhp[node->val] = ndh;
        depthMap[node->val] = depth;
        dpth[depth].push_back(ndh); 
        return ndh;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root, 0);
        for (auto& [depth, heights] : dpth) {
            sort(heights.rbegin(), heights.rend()); 
        }
        vector<int> answer;
        for (int query : queries) {
            int nd = depthMap[query];
            int ndh = mhp[query];
            int maxiH;
            if (dpth[nd].size() == 1) {
                maxiH = nd - 1;
            } else if (dpth[nd][0] == ndh) {
                maxiH = dpth[nd][1] + nd;
            } else {
                maxiH = dpth[nd][0] + nd;
            }
            answer.push_back(maxiH);
        }
        return answer;
    }
};