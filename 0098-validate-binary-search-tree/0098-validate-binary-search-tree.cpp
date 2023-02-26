class Solution {
public:
    bool isValidNode(TreeNode* root, TreeNode* &prev) {
        if (!root) return true;
        
        bool left = isValidNode(root->left, prev);

        if (prev && root->val <= prev->val) return false;
        prev = root;
        
        bool right = isValidNode(root->right, prev);
        return left && right;
    };
    
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = nullptr;
        return isValidNode(root, prev);
    };
};