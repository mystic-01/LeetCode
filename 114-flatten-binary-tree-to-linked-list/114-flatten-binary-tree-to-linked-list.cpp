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
// class Solution {
// public:
//     void toLinkedList(TreeNode* root, TreeNode*& prev) {
//         if (!root) return;
        
//         toLinkedList(root->right, prev);
//         toLinkedList(root->left, prev);
        
//         root->right = prev;
//         root->left = nullptr;
//         prev = root;
//     };
    
//     void flatten(TreeNode* root) {
//         TreeNode* prev = nullptr;
//         toLinkedList(root, prev);
//     };
// };

class Solution {
public:
    
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* prev = curr->left;
                while (prev->right) {
                    prev = prev->right;    
                };
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            };    
            curr = curr->right;
        };
    };
};















