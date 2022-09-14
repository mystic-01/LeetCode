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
    
    void dfs(TreeNode* root, int &ans, vector<int> &v) {
        v[root->val - 1]++;
        if (!root->left && !root->right) {
            int odd = 0;
            for (auto &num : v) odd += (num % 2);
            ans += odd <= 1;
        };
        if (root->left) dfs(root->left, ans, v);
        if (root->right) dfs(root->right, ans, v);
        v[root->val - 1]--;
    };
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        vector<int> v(9, 0);
        dfs(root, ans, v);
        return ans;
    };
};