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
    bool preOrder(TreeNode* root, int target) {
        if (!root) return 0;
        if (root && !root->left && !root->right) {
            return target == root->val ? 1 : 0;
        };
        return preOrder(root->left, target - root->val) || preOrder(root->right, target - root->val); 
    };
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return preOrder(root, targetSum);
    };
};