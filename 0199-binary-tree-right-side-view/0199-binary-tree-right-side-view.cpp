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
    void getRight(TreeNode* root,int currLevel, int &maxLevel,vector<int>&v){
        if(root==NULL) return;
        if(currLevel>maxLevel){
            v.push_back(root->val);
            maxLevel = currLevel;
        }
        getRight(root->right, currLevel+1,maxLevel,v);
        getRight(root->left, currLevel+1,maxLevel,v);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        int maxLevel=-1;
        getRight(root,0,maxLevel,v);
        return v;
    }
};