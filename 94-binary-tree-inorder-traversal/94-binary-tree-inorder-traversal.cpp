
// class Solution {
// public:
//     void inOrder (TreeNode* root, vector<int>& ans) {
//         if (root == nullptr) return;
        
//         inOrder (root->left, ans);
//         ans.push_back(root->val);
//         inOrder (root->right, ans);
//     };
    
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         // inOrder(root, ans);
//         TreeNode* node = root;
//         stack<TreeNode*> s;
//         while (true) {
//             if (node) {
//                 s.push(node);
//                 node = node->left;
//             } else {
//                 if (s.empty()) break;
//                 ans.push_back(s.top()->val);
//                 node = s.top()->right;
//                 s.pop();
//             };                        
//         };
//         return ans;        
//     };
// };


class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        // Morris Traversal
        vector<int> ans;
        if (!root) return ans;
        while (root) {
            if (!root->left) {
                ans.push_back(root->val);
                root = root->right;
            } else {
                TreeNode* prev = root->left;
                while (prev->right && prev->right != root) {
                    prev = prev->right;  
                };
                if (!prev->right) {
                    prev->right = root;
                    root = root->left;
                } else {
                    ans.push_back(prev->right->val);
                    root = prev->right->right; 
                    prev->right = nullptr;
                
                };
            };                               
        };
        return ans;        
    };
};





























