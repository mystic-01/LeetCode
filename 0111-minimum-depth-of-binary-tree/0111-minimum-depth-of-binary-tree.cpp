class Solution {
public:
    int preOrder(TreeNode* root, int count) {
        if (root == nullptr) return INT_MAX;
        if (root->left == nullptr && root->right == nullptr) return count;
        return min(preOrder(root->left, count + 1), preOrder(root->right, count + 1));
    };
    
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return preOrder(root, 1);
    };
};