class Solution {
public:
vector<string> path(TreeNode* root,string s){
    vector<string>v;
    if(root==NULL){
       
        return v;
    }  
    s+= to_string(root->val);
     if(root->left==NULL && root->right==NULL){
         v.push_back(s);
         return v;
     }
    vector<string> left = path(root->left, s + "->");
    vector<string> right = path(root->right, s + "->");
     v.insert(v.end(), left.begin(), left.end());
     v.insert(v.end(), right.begin(), right.end());

    return v;


}
    vector<string> binaryTreePaths(TreeNode* root) {
        
        string s;
        return path(root,s);
    }
};