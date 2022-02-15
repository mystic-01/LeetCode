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
    void dfs(TreeNode* root, vector<int>& ans) {
        if (!root) return;        
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    };
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> nums;
        dfs(root, nums);      
        int diff = INT_MAX;
        for (auto i = 0; i + 1 < nums.size(); i++) diff = min(diff, abs(nums[i] - nums[i + 1])); 
        return diff;
    };
};