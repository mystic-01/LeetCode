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
    int addGrandparent(TreeNode* root, int parent, int grandparent) {
        if (!root) return 0;
        
        return (grandparent % 2 == 0 ? root->val : 0) 
            + addGrandparent(root->left, root->val, parent) 
            + addGrandparent(root->right, root->val, parent);
    };
    
    int sumEvenGrandparent(TreeNode* root) {
        return addGrandparent(root, -1, -1);
    };
};