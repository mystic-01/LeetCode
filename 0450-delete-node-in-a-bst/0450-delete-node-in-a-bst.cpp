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
    
    bool deleteKey(TreeNode *root, TreeNode *keyNode, bool isKeyNodeALeftNode) {
        if (isLeafNode(keyNode)) {
            if (isKeyNodeALeftNode) {
                root->left = nullptr;
            } else {
                root->right = nullptr;                
            };
        } else if (!keyNode->left || !keyNode->right) {
            if (isKeyNodeALeftNode) {
                root->left = keyNode->right ? keyNode->right : keyNode->left;
            } else {
                root->right = keyNode->right ? keyNode->right : keyNode->left;
            };
        } else {
            TreeNode *leftMost = findLeftMost(keyNode->right);
            leftMost->left = keyNode->left;
            if (isKeyNodeALeftNode) {
                root->left = keyNode->right;
            } else {
                root->right = keyNode->right;                
            };
        };                                
        return true;                
    };
    
    bool findKey(TreeNode *root, int &key) {
        if (!root) {
            return false;
        };
        if (root->left && root->left->val == key) {
            return deleteKey(root, root->left, true);
        };
        if (root->right && root->right->val == key) {
            return deleteKey(root, root->right, false);
        };        
        return findKey(root->left, key) || findKey(root->right, key);
    };
    
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* dummy = new TreeNode(-1e9, root, nullptr);
        findKey(dummy, key);
        return dummy->left;
        // when found key, 
        // 1) Find leftmostNode in key's right = leftMost
        // 2) leftMost->left = key->left
        // 3) prev->left = key->right
    };
};