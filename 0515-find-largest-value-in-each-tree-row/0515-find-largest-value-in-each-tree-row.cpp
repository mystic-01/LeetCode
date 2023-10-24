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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if (root) q.push(root);
        
        while (!q.empty()) {
            int size = q.size(), best = q.front()->val;
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                q.pop();
                best = max(best, node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            };
            ans.push_back(best);
        };
        return ans;
    };
};