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
     TreeNode* arrayToBST(vector<int>& nums, int start, int end) {
         if (start > end) return nullptr;
         int idx = start + (end - start) / 2;
         TreeNode* root = new TreeNode(nums[idx]);
         
         root->left = arrayToBST(nums, start, idx - 1);
         root->right = arrayToBST(nums, idx + 1, end);
         return root;
    };
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return arrayToBST(nums, 0, n - 1);
    };
};