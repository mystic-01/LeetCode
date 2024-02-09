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
    int dfsLeftHeight(TreeNode* root) {
        int height = 1;
        while (root) {
            root = root->left;
            height++;
        };
        return height;
    };
    
    int dfsRightHeight(TreeNode* root) {
        int height = 1;
        while (root) {
            root = root->right;
            height++;
        };
        return height;
    };
    
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int lh = dfsLeftHeight(root->left);
        int rh = dfsRightHeight(root->right);
    
        if (lh == rh) return pow(2, lh) - 1; 

        return 1 + countNodes(root->left) + countNodes(root->right);
    };
};







