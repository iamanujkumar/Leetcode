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
    int minimumOperations(TreeNode* root) {
    int count = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        vector<int> v, v2;
        for (int i = 0; i < n; i++) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
            v.push_back(temp->val);
            v2.push_back(temp->val);
        }
        sort(v2.begin(), v2.end());
        vector<bool> visited(v.size(), false);
        unordered_map<int, int> valueToIndex;
        for (int i = 0; i < v.size(); i++) {
            valueToIndex[v[i]] = i;
        }
        for (int i = 0; i < v.size(); i++) {
            if (visited[i] || v2[i] == v[i]) {
                continue;
            }
            int cycleSize = 0;
            int x = i;
            while (!visited[x]) {
                visited[x] = true;
                x = valueToIndex[v2[x]];
                cycleSize++;
            }
            if (cycleSize > 1) {
                count += cycleSize - 1;
            }
        }
    }
    return count;
}

};