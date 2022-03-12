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
    bool isEvenOddTree(TreeNode* root) {
        bool isEvenLevel = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size(), prev = isEvenLevel ? INT_MIN : INT_MAX;
            for (auto i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (isEvenLevel) {
                    if (curr->val <= prev || curr->val % 2 == 0) return false;                                
                    prev = curr->val;
                } else {
                    if (curr->val >= prev || curr->val % 2 != 0) return false;                                
                    prev = curr->val;
                };
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            };
            isEvenLevel = !isEvenLevel;
        };
        return true;
    };
};