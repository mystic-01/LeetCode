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
    void addValue(TreeNode* root, int& parentVal) {
        if (!root) return;
        addValue(root->right, parentVal);

        root->val += parentVal;
        parentVal = root->val;
        
        addValue(root->left, parentVal);
    };
    
    TreeNode* bstToGst(TreeNode* root) {
        int parentVal = 0;
        addValue(root, parentVal);
        return root;
    };
};
