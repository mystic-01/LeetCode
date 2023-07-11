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
        
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        
        while (!q.empty() && k--) {
            int size = q.size();
            for (auto i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                };
                if (node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                };
                if (m[node] && !visited.count(m[node])) {
                    q.push(m[node]);
                    visited.insert(m[node]);
                };
            };
        };
        
        while (!q.empty()) {
            ans.push_back(q.front()->val); 
            q.pop();
        };        
        return ans;
    };
};