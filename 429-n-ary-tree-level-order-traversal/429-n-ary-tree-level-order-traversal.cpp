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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            for (auto i = 0; i < size; i++) { 
                Node* curr = q.front();
                q.pop();
                if (curr) {
                    for (auto &node : curr->children) if (node) q.push(node);
                    level.push_back(curr->val);
                };
            };
            if (level.size()) ans.push_back(level);
        };
        return ans;
    };
};