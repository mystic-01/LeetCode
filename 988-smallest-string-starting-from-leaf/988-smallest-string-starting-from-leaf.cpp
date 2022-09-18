class Solution {
public:
    
    void dfs(TreeNode* root, string curr, string &ans) {
        curr = char(97 + root->val) + curr;
        if (!root->left && !root->right) ans = !ans.length() ? curr : min(ans, curr);
        if (root->left) dfs(root->left, curr, ans);
        if (root->right) dfs(root->right, curr, ans);
    };
    
    
    string smallestFromLeaf(TreeNode* root) {
        string ans = "", curr = "";
        dfs(root, curr, ans);
        return ans;
    };
};