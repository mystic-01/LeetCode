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
    void preOrder(TreeNode* root, int target, vector<vector<int>>& ans, vector<int> ds) {
        if (!root) return;
        if (!root->left && !root->right) {
            ds.push_back(root->val);
            if (target - root->val == 0) ans.push_back(ds);
            ds.pop_back();
            return;
        };
        ds.push_back(root->val);
        preOrder(root->left, target - root->val, ans, ds);
        preOrder(root->right, target - root->val, ans, ds);        
        ds.pop_back();
    };

    
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        preOrder(root, target, ans, ds);
        return ans;
    };
};