/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

void fun(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent, TreeNode* target){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(temp->left){
            parent[temp->left]=temp;
            q.push(temp->left);
        }
        if(temp->right){
            parent[temp->right] = temp;
            q.push(temp->right);
        }
    }
}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        fun(root,parent,target);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int count=0;
        while(!q.empty()){
            int n=q.size();
            if(count++ == k) break;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if(parent[temp] && !visited[parent[temp]]){
                    q.push(parent[temp]);
                    visited[parent[temp]] = true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* temp= q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        return ans;

    }
};