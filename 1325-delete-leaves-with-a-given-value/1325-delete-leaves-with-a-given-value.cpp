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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return nullptr;  
        
        TreeNode* lh = removeLeafNodes(root->left, target);
        TreeNode* rh = removeLeafNodes(root->right, target);
        
        root->left = lh;
        root->right = rh;
        
        if (!lh && !rh && root->val == target) root = nullptr;
        
        return root;
    };
};