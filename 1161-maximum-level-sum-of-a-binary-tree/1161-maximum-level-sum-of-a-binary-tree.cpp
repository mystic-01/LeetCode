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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 0, maxLevel = 0, maxSum = INT_MIN;
        
        while (!q.empty()) {
            int size = q.size(), sum = 0;
            for (auto i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                sum += curr->val;
            };
            ++level;
            if (sum > maxSum) maxLevel = level, maxSum = sum;
        };
        return maxLevel;
    };
};