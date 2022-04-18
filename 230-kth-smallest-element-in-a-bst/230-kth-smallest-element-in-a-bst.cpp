class Solution {
public:
    void dfs(TreeNode* root, int& k, int& ans) {
        if (!root) return;
        dfs(root->left, k, ans);
        k--;
        if (k == 0) ans = root->val;
        if (k <= 0) return;
        dfs(root->right, k, ans);
    };
    
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        dfs(root, k, ans);
        return ans;                 
    };
};
