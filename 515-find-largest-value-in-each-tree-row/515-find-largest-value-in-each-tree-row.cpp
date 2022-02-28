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
        if (!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size(), best = INT_MIN;
            for (auto i = 0; i < size; i++) {
                if (q.front()->left) q.push(q.front()->left);                
                if (q.front()->right) q.push(q.front()->right);
                best = max(best, q.front()->val);
                q.pop();
            };
            ans.push_back(best);
        };
        return ans;
    };
};