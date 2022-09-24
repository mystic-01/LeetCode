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
    vector<int> preorder(Node* root) {
        vector<int> ans;
        stack<Node*> st;
        if (root) st.push(root);

        while (!st.empty()) {
            Node* curr = st.top();
            st.pop();
            ans.push_back(curr->val); 

            int size = curr->children.size() - 1;
            for (auto i = size; i >= 0; i--) st.push(curr->children[i]);  
        };
        
        return ans;
    };
};




