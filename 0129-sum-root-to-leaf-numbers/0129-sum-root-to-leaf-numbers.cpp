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
    int sumTillLeaf(TreeNode* root, int num) {
        if (!root) return 0;
        if (!root->left && !root->right) return num * 10 + root->val;
        return sumTillLeaf(root->left, num * 10 + root->val) + sumTillLeaf(root->right, num * 10 + root->val); 
    };
    
    int sumNumbers(TreeNode* root) {
        return sumTillLeaf(root, 0);
    };
};