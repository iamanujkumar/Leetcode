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
class FindElements {
private:
    unordered_set<int> mp;
    void recoverTree(TreeNode* node, int count) {
        if (!node) return;
        node->val = count;
        mp.insert(count);
        if (node->left) recoverTree(node->left, 2 * count + 1);
        if (node->right) recoverTree(node->right, 2 * count + 2);
    }
public:
    FindElements(TreeNode* root) {
        recoverTree(root, 0);
    }
    bool find(int target) {
        return mp.count(target) > 0; 
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */