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
    TreeNode* findLeftMost(TreeNode *root) {
        while (root->left) {
            root = root->left;    
        };    
        return root;
    };
    
    bool isLeafNode(TreeNode *root) {
        return !root->left && !root->right;
    };
    
    bool findAndDeleteKey(TreeNode *root, int &key) {
        if (!root) {
            return false;
        };
        if (root->left) {
            if (root->left->val == key) {
                TreeNode *keyNode = root->left; 
                if (isLeafNode(keyNode)) {
                    root->left = nullptr;
                } else if (!keyNode->left) {
                    root->left = keyNode->right;
                } else if (!keyNode->right) {
                    root->left = keyNode->left;
                } else {
                    TreeNode *leftMost = findLeftMost(keyNode->right);
                    leftMost->left = keyNode->left;
                    root->left = keyNode->right;
                };                                
                return true;
            } else {
                if (findAndDeleteKey(root->left, key)) {
                    return true;                        
                };
            };
        };
        if (root->right) {
            if (root->right->val == key) {
                TreeNode *keyNode = root->right; 
                if (isLeafNode(keyNode)) {
                    root->right = nullptr;
                } else if (!keyNode->right) {
                    root->right = keyNode->left;
                } else if (!keyNode->left) {
                    root->right = keyNode->right;
                } else {
                    TreeNode *leftMost = findLeftMost(keyNode->right);
                    leftMost->left = keyNode->left;
                    root->right = keyNode->right;
                };                                
                return true;
            } else {
                if (findAndDeleteKey(root->right, key)) {
                    return true;    
                };
            };
        };        
        return false;
    };
    
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* dummy = new TreeNode(-1e9);
        dummy->left = root;
        findAndDeleteKey(dummy, key);
        return dummy->left;
        // when found key, 
        // 1) Find leftmostNode in key's right = leftMost
        // 2) prev->left = key->right
        // 3) leftMost->left = key->left
    };
};