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
    int preOrder(Node* root, int count) {
        if (root == nullptr) return count;
        
        int x = count;
        for (auto i = 0; i < root->children.size(); i++) {
            int curr = preOrder(root->children[i], count + 1);
            if (curr > x) x = curr;
        };
        return x;
    };        

    
    int maxDepth(Node* root) {
        if (root == nullptr) return 0; 
        return preOrder(root, 1);        
    };
};