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
    int checkDepth(TreeNode* root) {
        if (!root) return 0;
        
        int left = checkDepth(root->left);
        left = left == -1 ? -1 : left + 1;

        int right = checkDepth(root->right);
        right = right == -1 ? -1 : right + 1;
        
        if (left == -1 || right == -1 || abs(left - right) > 1) return -1;
        return max(left, right);
    };

    
    bool isBalanced(TreeNode* root) {
        if (checkDepth(root) == -1) return false;
        return true;
    };
};