class Solution {
public:
TreeNode* createBst(vector<int>v,int  s,int e){
    if(s>e){
return NULL ;
    }
    int mid=(s+e)/2;
    TreeNode* root=new TreeNode(v[mid]);
    root->left=createBst(v,s,mid-1);
    root->right=createBst(v,mid+1,e);
    return root;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBst(nums,0,nums.size()-1);
    }
};