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
    int dfs(TreeNode* root, int& best) {
        if (!root) return 0;
        
        int lSum = max(dfs(root->left, best), 0);
        int rSum = max(dfs(root->right, best), 0);
        
        best = max(best, root->val + lSum + rSum);
        return root->val + max(lSum, rSum);
    };
    
    int maxPathSum(TreeNode* root) {
        int best = INT_MIN;
        dfs(root, best);   
        return best;
    };
};