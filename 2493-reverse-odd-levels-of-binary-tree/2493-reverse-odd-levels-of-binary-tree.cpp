class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr; 
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> nodes; 
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                nodes.push_back(node);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (level % 2 == 1) {
                int n = nodes.size();
                for (int i = 0; i < n / 2; ++i) {
                    swap(nodes[i]->val, nodes[n - i - 1]->val);
                }
            }
            level++;
        }
        return root;
    }
};
