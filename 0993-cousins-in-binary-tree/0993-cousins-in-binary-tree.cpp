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
    
    pair<int, bool> dfs(TreeNode* root, int depth, int &x, int &y) {
        if (root->val == x || root->val == y) return {depth, false};         
        
        pair<int, bool> left = {-1, false}, right = {-2, false};
        if (root->left) left = dfs(root->left, depth + 1, x, y);
        if (root->right) right = dfs(root->right, depth + 1, x, y);

        
        if (left.first < 0) return right;
        else if (right.first < 0) return left;
        else return {left.first, left.first == right.first && left.first > depth + 1};
    };
    
    bool isCousins(TreeNode* root, int x, int y) {
        return dfs(root, 0, x, y).second;
    };
};