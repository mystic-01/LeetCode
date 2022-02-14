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
    int preOrder(Node* root) {
        if (root == nullptr) return 0;
        int x = 1;
        for (auto i = 0; i < root->children.size(); i++) {
            x = max(x, preOrder(root->children[i]) + 1);
        };
        return x;
    };        

    
    int maxDepth(Node* root) {
        return preOrder(root);        
    };
};