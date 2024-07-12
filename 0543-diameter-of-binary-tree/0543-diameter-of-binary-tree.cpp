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
int fun(TreeNode *root, int &dm){
    if(root==NULL){
            return 0;
        }
        int lh=fun(root->left,dm);
        int rh=fun(root->right,dm);
        dm=max(dm,lh+rh);
        return max(lh,rh)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        int dm=0;
        fun(root,dm);
        return dm;
    }
};