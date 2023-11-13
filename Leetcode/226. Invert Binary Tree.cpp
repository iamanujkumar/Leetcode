class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)return NULL;
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        TreeNode * left=invertTree(root->left);
        TreeNode* right=invertTree(root->right);
        return root;

    }
};