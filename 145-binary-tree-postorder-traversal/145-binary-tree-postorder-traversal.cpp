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
class Solution {
public:
    void postOrder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        
        postOrder(root->left, ans);
        postOrder(root->right, ans);
        ans.push_back(root->val);
    };
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        // postOrder(root, ans);
        if (!root) return {};
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            if (root->left) s.push(root->left);
            if (root->right) s.push(root->right);
        };
        
        reverse(ans.begin(), ans.end());        
        return ans;
    };
};