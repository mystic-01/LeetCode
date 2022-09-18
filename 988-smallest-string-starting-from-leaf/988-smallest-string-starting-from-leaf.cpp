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
    
    void dfs(TreeNode* root, string curr, string &ans) {
        curr = char(97 + root->val) + curr;
        if (!root->left && !root->right) ans = ans == "" ? curr : min(ans, curr);
        if (root->left) dfs(root->left, curr, ans);
        if (root->right) dfs(root->right, curr, ans);
    };
    
    
    string smallestFromLeaf(TreeNode* root) {
        string ans = "", curr = "";
        dfs(root, curr, ans);
        return ans;
    };
};