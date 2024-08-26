/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
void fun(Node* root, vector<int>& v) {
    if (root == NULL) return;
    for(Node *child:root->children)
    fun(child, v);
    v.push_back(root->val);
}

vector<int> postorder(Node* root) {
    vector<int> v;
    fun(root, v);
    return v;
}

};