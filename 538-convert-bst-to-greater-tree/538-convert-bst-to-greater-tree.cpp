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
    void addVal(TreeNode* root, int& parentVal) {
        // right root left
        if (!root) return;
        addVal(root->right, parentVal);
        root->val += parentVal;
        parentVal = root->val;
        addVal(root->left, parentVal);
    };
    
    TreeNode* convertBST(TreeNode* root) {
        int parentVal = 0;
        addVal(root, parentVal);
        return root;
    };
};