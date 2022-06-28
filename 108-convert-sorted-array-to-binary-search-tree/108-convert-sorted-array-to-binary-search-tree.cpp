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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size(), idx = n / 2;
        if (!n) return nullptr;
        TreeNode* root = new TreeNode(nums[idx]);
        
        vector<int> left, right;
        for (auto i = 0; i < idx; i++) left.push_back(nums[i]);
        for (auto i = idx + 1; i < n; i++) right.push_back(nums[i]);

        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    };
};