class Solution {
public:
    void preOrder (TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        ans.push_back(root->val);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    };
    
    vector<int> preorderTraversal(TreeNode* root) {
        // preOrder(root, ans);
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            if (root->right) s.push(root->right);
            if (root->left) s.push(root->left);
            ans.push_back(root->val);
        };
        return ans;
    };
};