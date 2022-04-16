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
    void trimmer(TreeNode* root, int low, int high) {
        if (!root) return;
        if (root->left) {
            if (root->left->val < low) {
                root->left = root->left->right;
                trimmer(root, low, high);
            };
            trimmer(root->left, low, high);
        };
        if (root->right) {
            if (root->right->val > high) {
                root->right = root->right->left;
                trimmer(root, low, high);
            } else if (root->right->val < low) {
                root->right = root->right->right;
                trimmer(root, low, high);
            };
            trimmer(root->right, low, high);
        };
    };
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* dummy = new TreeNode(low, nullptr, root);
        trimmer(dummy, low, high);
        return dummy->right;
    };
};