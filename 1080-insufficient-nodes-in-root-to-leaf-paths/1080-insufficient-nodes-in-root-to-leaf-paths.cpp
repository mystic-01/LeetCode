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
    bool isGoodNode(TreeNode* root, int sum, int &limit) {
        if (!root) return 0;
        int sumTillHere = sum + root->val; 
        
        if (!root->left && !root->right) return sumTillHere >= limit;
        
        bool left = isGoodNode(root->left, sumTillHere, limit);         
        bool right = isGoodNode(root->right, sumTillHere, limit);
        
        if (!left) root->left = nullptr;
        if (!right) root->right = nullptr;
        
        return left || right; 
    };
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int sum = 0;
        bool isRootGood = isGoodNode(root, sum, limit);
        if (isRootGood) return root;
        return nullptr;
    };
};