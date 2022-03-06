class Solution {
public:
    void toLinkedList(TreeNode* root, TreeNode*& prev) {
        if (!root) return;
        
        toLinkedList(root->right, prev);
        toLinkedList(root->left, prev);
        
        root->right = prev;
        root->left = nullptr;
        prev = root;
    };
    
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        toLinkedList(root, prev);
    };
};

// Using Morris Traversal O(1) Space 
// class Solution {
// public:
    
//     void flatten(TreeNode* root) {
//         TreeNode* curr = root;
//         while (curr) {
//             if (curr->left) {
//                 TreeNode* prev = curr->left;
//                 while (prev->right) {
//                     prev = prev->right;    
//                 };
//                 prev->right = curr->right;
//                 curr->right = curr->left;
//                 curr->left = nullptr;
//             };    
//             curr = curr->right;
//         };
//     };
// };















