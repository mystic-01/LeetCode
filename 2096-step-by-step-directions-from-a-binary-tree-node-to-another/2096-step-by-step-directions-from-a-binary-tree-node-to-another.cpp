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
    void dfs(TreeNode* root, int &start, int &end, int &depth, int &startDepth, string &ds, string &ans) {
        if (root->val == start) startDepth = depth;         
        if (root->val == end) ans = ds;
        if (startDepth > -1 && ans.size() > 0) return;
        
        depth++;
        ds += 'L';
        if (root->left) dfs(root->left, start, end, depth, startDepth, ds, ans);        
        ds.pop_back();
        ds += 'R';
        if (root->right) dfs(root->right, start, end, depth, startDepth, ds, ans);        
        ds.pop_back();        
        depth--;        
    };
    
    TreeNode* lca(TreeNode* root, int &start, int &end) {
        if (!root) return root;
        if (root->val == start || root->val == end) return root;
        
        TreeNode* left = lca(root->left, start, end);
        TreeNode* right = lca(root->right, start, end);
        
        if (!left) return right;
        else if (!right) return left;
        else return root;
    };
    
    string getDirections(TreeNode* root, int start, int end) {
        int depth = 0, startDepth = -1;
        string ds = "", ans = "";
        
        TreeNode* newRoot = lca(root, start, end);
        dfs(newRoot, start, end, depth, startDepth, ds, ans);        
        
        while (startDepth--) ans = "U" + ans;
        
        return ans;
    };
};