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
    
    void dfs(TreeNode* root, int &ans, unordered_map<int, int> &m) {
        m[root->val]++;
        if (!root->left && !root->right) {
            int odd = 0;
            for (auto &num : m) odd += (num.second % 2);
            ans += odd <= 1;
        };
        if (root->left) dfs(root->left, ans, m);
        if (root->right) dfs(root->right, ans, m);
        m[root->val]--;
    };
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        unordered_map<int, int> m;
        dfs(root, ans, m);
        return ans;
    };
};