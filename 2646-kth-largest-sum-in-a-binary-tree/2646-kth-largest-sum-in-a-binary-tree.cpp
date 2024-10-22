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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>val;
        if(root==NULL) return val.size();
        queue<TreeNode*>q;
        int maxi=0;
        q.push(root);
        while(!q.empty()){
            long long n=q.size();
            vector<int>v;
            for(int i=0;i<n;i++){
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                v.push_back(temp->val);
                
            }
            long long sum=0;
            for(int i=0;i<v.size();i++){
                sum+=v[i];
            }
            val.push_back(sum);
        }
        if(k>val.size()) return -1;
        sort(val.begin(),val.end());
        return val[val.size()-k];
        
    }
};