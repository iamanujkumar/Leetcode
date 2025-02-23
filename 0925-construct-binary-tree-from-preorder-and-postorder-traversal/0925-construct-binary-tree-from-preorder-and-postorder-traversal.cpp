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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> pre;
        for (int i = 0; i < postorder.size(); i++) {
            pre[postorder[i]] = i;
        }
        int preIndex = 0;
        return buildTree(preorder, postorder, preIndex, 0, postorder.size() - 1, pre);
    }
private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, int& preIndex, 
                        int left, int right, unordered_map<int, int>& pre) {
        if (left > right || preIndex >= preorder.size()) return nullptr;
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        if (left == right || preIndex >= preorder.size()) return root;
        int klchd = preorder[preIndex];
        int lfchad = pre[klchd];
        root->left = buildTree(preorder, postorder, preIndex, left, lfchad, pre);
        root->right = buildTree(preorder, postorder, preIndex, lfchad + 1, right - 1, pre);
        return root;
    }
};
