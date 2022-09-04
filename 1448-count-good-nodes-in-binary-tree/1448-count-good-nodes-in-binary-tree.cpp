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
    void dfs(TreeNode* root, int maxima, int &ans) {
        if (root->val >= maxima) ans++;
        if (root->left) dfs(root->left, max(maxima, root->val), ans);
        if (root->right) dfs(root->right, max(maxima, root->val), ans);
        return;
    };
    
    int goodNodes(TreeNode* root) {
        int ans = 0, maxima = INT_MIN;
        dfs(root, maxima, ans);
        return ans;
    };
};