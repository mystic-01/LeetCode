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
private:
    void getParent(TreeNode* &root, map<TreeNode*, TreeNode*> &parent) {
        if (!root) return;
        if (root->left) {
            parent[root->left] = root;
            getParent(root->left, parent);
        };
        if (root->right) {
            parent[root->right] = root;
            getParent(root->right, parent);
        };
    };

    TreeNode* getNode(TreeNode* &root, int &target) {
        if (!root) return nullptr;
        if (root->val == target) return root;
        
        TreeNode* left = getNode(root->left, target);
        if (left) return left;

        TreeNode* right = getNode(root->right, target);
        if (right) return right;
        
        return nullptr;
    };
    
    int countNodesBfs(TreeNode* &root, map<TreeNode*, TreeNode*> &parent, set<TreeNode*> &visited) {
        int nodes = 0;
        queue<TreeNode*> q;
        if (root) q.push(root);
        visited.insert(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            nodes++;
            if (node->left && !visited.count(node->left)) {
                q.push(node->left); 
                visited.insert(node->left);
            };
            if (node->right && !visited.count(node->right)) {
                q.push(node->right); 
                visited.insert(node->right);
            };
            if (parent[node] && !visited.count(parent[node])) {
                q.push(parent[node]); 
                visited.insert(parent[node]);
            };
        };
        
        return nodes;        
    };
    
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* node = getNode(root, x);
        
        map<TreeNode*, TreeNode*> parent;
        getParent(root, parent);
        
        set<TreeNode*> visited;
        visited.insert(node);
        
        int a = countNodesBfs(node->left, parent, visited);
        int b = countNodesBfs(node->right, parent, visited);
        int c = countNodesBfs(parent[node], parent, visited);

        return a > b + c || b > a + c || c > a + b;
    };
};