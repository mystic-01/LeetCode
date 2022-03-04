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
    void makeParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent) {
        if (!root) return;
        if (root->left) {
            parent[root->left] = root;
            makeParents(root->left, parent);
        };
        if (root->right) {
            parent[root->right] = root;
            makeParents(root->right, parent);
        };
    };
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root || !target) return {};
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> parent;
        makeParents(root, parent);
        parent[root] = nullptr;
        unordered_set<TreeNode*> visited;
        
        queue<TreeNode*> q;
        q.push(target);

        while (!q.empty() && k--) {
            int size = q.size();
            for (auto i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                visited.insert(curr);
                q.pop();
                
                if (curr->left && !visited.count(curr->left))
                    q.push(curr->left);
                
                if (curr->right && !visited.count(curr->right))
                    q.push(curr->right);
                
                if (parent[curr] && !visited.count(parent[curr]))
                    q.push(parent[curr]);
            };
        };
        
        while (!q.empty())
            ans.push_back(q.front()->val), q.pop();     
        
        return ans;
    };
};







