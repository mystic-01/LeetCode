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
    pair<int, int> recurse(TreeNode* root, int &ans) {
        pair<int, int> left, right;
        int mini = root->val, maxi = root->val;
        if (root->left) {
            left = recurse(root->left, ans);
            mini = min(mini, left.first);
            maxi = max(maxi, left.second);
        };
        if (root->right) {
            right = recurse(root->right, ans);
            mini = min(mini, right.first);
            maxi = max(maxi, right.second);
        };
        ans = max({ans, abs(root->val - mini), abs(root->val - maxi)});
        return {mini, maxi};
    };
    
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        recurse(root, ans);
        return ans;
    };
};