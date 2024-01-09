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
    void preorder(TreeNode *root, vector<int> &treeVec) {
        if (!root) return;
        preorder(root->left, treeVec);
        if (!root->left && !root->right) treeVec.push_back(root->val);
        preorder(root->right, treeVec);
    };
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> treeVec1, treeVec2;
        preorder(root1, treeVec1);
        preorder(root2, treeVec2);
        return treeVec1 == treeVec2; 
    };
};