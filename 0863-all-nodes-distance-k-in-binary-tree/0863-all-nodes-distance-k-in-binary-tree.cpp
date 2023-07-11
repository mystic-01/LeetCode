/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getParent(TreeNode *root, map<TreeNode*, TreeNode*> &m) {
        if (root->left) {
            m[root->left] = root;
            getParent(root->left, m);        
        };
        if (root->right) {
            m[root->right] = root;
            getParent(root->right, m);        
        };
    };
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        map<TreeNode*, TreeNode*> m;
        set<TreeNode*> visited;
        getParent(root, m);
        m[root] = nullptr;
        
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        visited.insert(target);
        
        while (!q.empty()) {
            int size = q.size();
            for (auto i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                int dist = q.front().second;
                q.pop();
                
                if (dist == k) {
                    ans.push_back(node->val);
                    continue;
                };
                if (node->left && !visited.count(node->left)) {
                    q.push({node->left, dist + 1});
                    visited.insert(node->left);
                };
                if (node->right && !visited.count(node->right)) {
                    q.push({node->right, dist + 1});
                    visited.insert(node->right);
                };
                if (m[node] && !visited.count(m[node])) {
                    q.push({m[node], dist + 1});
                    visited.insert(m[node]);
                };
            };
        };
        return ans;
    };
};