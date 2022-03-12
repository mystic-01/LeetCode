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
    bool checkLeaves(TreeNode* root, vector<int>& leaves, int& idx) {
        if (!root) return 1;
        if (!root->left && !root->right) { 
            if (idx < leaves.size() && root->val == leaves[idx]) leaves[idx++] = -1; 
            else return 0;
            return 1;
        };

        return checkLeaves(root->left, leaves, idx) && checkLeaves(root->right, leaves, idx);
    };
    
    void getLeaves(TreeNode* root, vector<int>& leaves) {
        if (!root) return;
        if (!root->left && !root->right) {
            leaves.push_back(root->val);
            return;
        };
        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    };
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        int idx = 0;
        vector<int> leaves;
        getLeaves(root1, leaves);
        return checkLeaves(root2, leaves, idx) && leaves[leaves.size() - 1] == -1;
    };
};