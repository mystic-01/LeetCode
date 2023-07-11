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
    void getParent(TreeNode * &root, map<TreeNode*, TreeNode*> &m) {
        if (root->left) {
            m[root->left] = root;
            getParent(root->left, m);
        };
        if (root->right) {
            m[root->right] = root;
            getParent(root->right, m);
        };        
    };
    
    TreeNode *findNode(TreeNode * &root, int &start) {
        if (!root) return nullptr;
        if (root->val == start) return root;
        TreeNode *left = findNode(root->left, start);
        if (left) return left;
        TreeNode *right = findNode(root->right, start);
        return right;    
    };    
    
    int amountOfTime(TreeNode *root, int val) {
        TreeNode *start = findNode(root, val);    
        map<TreeNode*, TreeNode*> m;
        getParent(root, m);
        m[root] = nullptr;
        
        queue<TreeNode*> q;
        set<TreeNode*> visited;
        
        q.push(start);
        visited.insert(start);
        
        int time = -1;
        while (!q.empty()) {
            time++;
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
        return time;
    };
};





