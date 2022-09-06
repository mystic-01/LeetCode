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
    int dfs(TreeNode* root, int &tiltValue) {
        if (!root) return 0;
        int left = dfs(root->left, tiltValue);
        int right = dfs(root->right, tiltValue);
        int val = root->val;
        
        tiltValue += abs(left - right);
        return left + right + val;
    };
    
    
    int findTilt(TreeNode* root) {
        int tiltValue = 0;
        dfs(root, tiltValue);
        return tiltValue;
    };
};