class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        if (root->left) invertTree(root->left);
        if (root->right) invertTree(root->right);
        TreeNode* temp = root->left;
        root->left = root->right, root->right = temp;

        return root;
    };
};
