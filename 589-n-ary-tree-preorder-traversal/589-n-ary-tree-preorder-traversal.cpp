class Solution {
public:
    void preOrder(Node* root, vector<int>& ans) {
        if (!root) return;
        ans.push_back(root->val);
        for (auto i = 0; i < root->children.size(); i++) preOrder(root->children[i], ans);
    };

    vector<int> preorder(Node* root) {
        vector<int> ans;
        preOrder(root, ans);
        return ans;
    };
};