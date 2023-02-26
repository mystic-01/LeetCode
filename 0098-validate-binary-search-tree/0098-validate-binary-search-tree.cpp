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
    TreeNode* prev;    
    bool isValidNode(TreeNode* root) {
        if (!root) return true;
        
        bool left = isValidNode(root->left);

        if (prev && (root->val <= prev->val)) return false;
        prev = root;

        bool right = isValidNode(root->right);
        return left && right;
    };
    
    bool isValidBST(TreeNode* root) {
        return isValidNode(root);
    };
};





