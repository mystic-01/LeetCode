class Solution {
public:
    void dfs(TreeNode* root, int& k, int& ans) {
        if (!root) return;
        dfs(root->left, k, ans);
        k--;
        if (k == 0) ans = root->val;
        dfs(root->right, k, ans);
    };
    
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        dfs(root, k, ans);
        return ans;                 
    };
};
