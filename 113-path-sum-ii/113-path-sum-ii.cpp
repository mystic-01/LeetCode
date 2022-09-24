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
    void findSum (TreeNode* root, int &targetSum, vector<vector<int>> &ans, vector<int> &ds) {
        targetSum -= root->val;
        ds.push_back(root->val);
        if (!root->left && !root->right && !targetSum) ans.push_back(ds);                             

        if (root->left) findSum(root->left, targetSum, ans, ds);
        if (root->right) findSum(root->right, targetSum, ans, ds);
        targetSum += root->val;
        ds.pop_back();
    };
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> ds;        
        if (root) findSum(root, targetSum, ans, ds);
        return ans;
    };
};