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
    int preOrder(TreeNode* root, int count) {
        if (root == nullptr) return count;
        return max(preOrder(root->left, count + 1), preOrder(root->right, count + 1));
    };
    
    int maxDepth(TreeNode* root) {
      return preOrder(root, 0);
    };
};