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
    bool hasOne(TreeNode* root) {
        if (!root) return false;
        bool left = hasOne(root->left); 
        bool right = hasOne(root->right); 
        if (!left) root->left = nullptr;
        if (!right) root->right = nullptr;
        return left || right || root->val == 1;
    };
    
    TreeNode* pruneTree(TreeNode* root) {
        hasOne(root);
        if (!root->left && !root->right && root->val == 0) return nullptr;
        return root;
    };
};