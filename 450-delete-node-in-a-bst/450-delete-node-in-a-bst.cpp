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
    TreeNode* helper(TreeNode* root) {
        if (!root->right) return root->left;
        else if (!root->left) return root->right;
        
        TreeNode* rightChild = root->right;
        TreeNode* leftChild = root->left, *curr = leftChild;
        
        while (curr->right) curr = curr->right;
        curr->right = rightChild;
        
        return leftChild;
    };
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val == key) return helper(root);
        
        TreeNode* curr = root;
        while (curr) {
            if (curr->val > key) {
                if (curr->left && curr->left->val == key) {
                    curr->left = helper(curr->left);
                    break;
                };            
                curr = curr->left;
            } else {
                if (curr->right && curr->right->val == key) {
                    curr->right = helper(curr->right);
                    break;
                };
                curr = curr->right;
            };
        };
        return root;
    };
};







