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
    
    bool fun(TreeNode* l,TreeNode* r){
        if(l==NULL && r==NULL)return true;
        if(l ==NULL && r!=NULL) return false;
        if(l!=NULL && r==NULL) return false;
        bool lf=fun(l->left,r->right);
        bool rf=fun(l->right,r->left);
        bool value=(l->val==r->val);
        return (value && lf && rf);
        
    }

    bool isSymmetric(TreeNode* root) {

       if(root==NULL) return false;
      return fun(root->left,root->right);
    }
};