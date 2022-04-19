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
    void checkBST(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &second, TreeNode* &last) {
        if (!root) return;
        checkBST(root->left, prev, first, second, last);
        if (prev && root->val < prev->val) {
            if (!first) first = prev, second = root;
            else last = root;
        };
        prev = root;
        checkBST(root->right, prev, first, second, last);        
    };
    
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr, * second = nullptr, * last = nullptr, * prev = nullptr;
        checkBST(root, prev, first, second, last);        
        swap(first->val, last ? last->val : second->val);
    };
};