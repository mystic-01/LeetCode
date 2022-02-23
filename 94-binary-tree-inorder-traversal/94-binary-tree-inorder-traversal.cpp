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
    void inOrder (TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        
        inOrder (root->left, ans);
        ans.push_back(root->val);
        inOrder (root->right, ans);
    };
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        // inOrder(root, ans);
        TreeNode* node = root;
        stack<TreeNode*> s;
        while (true) {
            if (node) {
                s.push(node);
                node = node->left;
            } else {
                if (s.empty()) break;
                ans.push_back(s.top()->val);
                node = s.top()->right;
                s.pop();
            };                        
        };
        return ans;        
    };
};