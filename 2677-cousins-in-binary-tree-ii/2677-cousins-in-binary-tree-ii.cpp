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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == NULL) return NULL;
        vector<long long> sum;
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
            sum.push_back(levelSum);
        }
        q.push(root);
        root->val = 0;
        int currentLevel = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                long long siblingSum = 0;
                if (temp->left) {
                    siblingSum += temp->left->val;
                }
                if (temp->right) {
                    siblingSum += temp->right->val;
                }
                if (temp->left) {
                    temp->left->val = sum[currentLevel + 1] - siblingSum;
                    q.push(temp->left);
                }
                if (temp->right) {
                    temp->right->val = sum[currentLevel + 1] - siblingSum;
                    q.push(temp->right);
                }
            }
            currentLevel++;
        }
        return root;
    }
};
