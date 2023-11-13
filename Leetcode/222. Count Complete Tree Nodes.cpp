class Solution {
public:
int count(TreeNode * root,int &ans){
     if(root==NULL)return 0;
        ans+=1;
        int left= count(root->left,ans);
        int right= count(root->right,ans);

        return ans;

}
    int countNodes(TreeNode* root) {
        int ans=0;
       return count(root,ans);
    }
};