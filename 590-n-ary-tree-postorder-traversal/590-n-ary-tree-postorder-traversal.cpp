class Solution {
public:
    void postOrder(Node* root, vector<int>& ans) {
        if (root == nullptr) return;
        
        for (auto i = 0; i < root->children.size(); i++) {
            postOrder(root->children[i], ans);
        };
        ans.push_back(root->val);
    };
    
    vector<int> postorder(Node* root) {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    };
};