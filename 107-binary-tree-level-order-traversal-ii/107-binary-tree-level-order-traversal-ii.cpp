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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> ds;
            for (auto i = 0; i < size; i++) {
                if (q.front()->left) q.push(q.front()->left);                
                if (q.front()->right) q.push(q.front()->right);   
                ds.push_back(q.front()->val);
                q.pop();
            };
            ans.push_back(ds);
        };
        
        // int i = 0, j = ans.size() - 1;
        // while (i < j) swap(ans[i++], ans[j--]);
        reverse(ans.begin(), ans.end());
        return ans;
    };
};