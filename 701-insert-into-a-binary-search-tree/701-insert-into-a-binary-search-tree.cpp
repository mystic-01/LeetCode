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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        
        TreeNode* curr = root;
        while (curr->left || curr->right) {
            if (curr->val > val) {
                if (!curr->left) {
                    curr->left = new TreeNode(val);
                    return root;
                };
                curr = curr->left;
            } else {
                if (!curr->right) {
                    curr->right = new TreeNode(val);
                    return root;
                };
                curr = curr->right;                
            };
        };
        
        if (curr->val > val) curr->left = new TreeNode(val);
        else curr->right = new TreeNode(val);
        return root;
    };
};