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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool isReverse = false;
        while (!q.empty()) {
            vector<int> ds;
            int size = q.size();
            for (auto i = 0; i < size; i++) {
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                ds.push_back(q.front()->val);
                q.pop();
            };
            if (isReverse) reverse(ds.begin(), ds.end());
            ans.push_back(ds);
            isReverse = !isReverse;
        };
        return ans;
    };
};