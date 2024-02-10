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
    TreeNode *buildTree(int &idx, vector<int> &preorder, int &upperBound) {
        if (idx == preorder.size() || preorder[idx] >= upperBound) {
            return nullptr;    
        };
        
        TreeNode *node = new TreeNode(preorder[idx++]);
        
        node->left = buildTree(idx, preorder, node->val);
        node->right = buildTree(idx, preorder, upperBound);
        
        return node;
    };
    
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        int idx = 0, upperBound = 2147483647;
        return buildTree(idx, preorder, upperBound);
    };
};