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
        int x = preOrder(root->left, count + 1);
        int y = preOrder(root->right, count + 1);
        return max(x, y);
    };
    
    int maxDepth(TreeNode* root) {
      return preOrder(root, 0);
    };
};