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
    int dfs(TreeNode* root, int depth) {
        if (!root) return depth;
        
        int lh = dfs(root->left, depth + 1);
        int rh = dfs(root->right, depth + 1);
        
        if (lh == -1 || rh == -1 || abs(lh - rh) > 1) return -1;
        return max(lh, rh);
    };
    
    bool isBalanced(TreeNode* root) {
        return dfs(root, 0) != -1;
    };
};