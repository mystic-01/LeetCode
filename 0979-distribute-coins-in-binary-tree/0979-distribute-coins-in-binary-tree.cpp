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
    int moves = 0;   
    
    int recurse(TreeNode* root) {
        if (!root) {
            return 0;    
        };
        
        if (!root->left && !root->right) {
            return root->val - 1;
        };            
        
        int left = recurse(root->left);
        int right = recurse(root->right);
        
        moves += (abs(left) + abs(right));
        return root->val - 1 + left + right;
    };
    
    int distributeCoins(TreeNode* root) {
        recurse(root);
        return moves;
    };
};