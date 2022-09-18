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
    void dfs(TreeNode* root, int currSum, int & sum) {
        currSum = (currSum * 10) + root->val;
        
        if (!root->left && !root->right) sum += currSum;
        
        if (root->left) dfs(root->left, currSum, sum);
        if (root->right) dfs(root->right, currSum, sum);
    };
    
    
    int sumNumbers(TreeNode* root) {
        int sum = 0, currSum = 0;
        dfs(root, currSum, sum);
        return sum;
    };
};