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
    long long kthLargestLevelSum(TreeNode* root, int k) {
    if (root == NULL) return -1;
    vector<long long> val; 
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        long long levelSum = 0;
        for (int i = 0; i < n; i++) {
            TreeNode* temp = q.front();
            q.pop();
            levelSum += temp->val;
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        val.push_back(levelSum);
    }
    if (k > val.size()) return -1;
    nth_element(val.begin(), val.end() - k, val.end());
    return val[val.size() - k];
}

};