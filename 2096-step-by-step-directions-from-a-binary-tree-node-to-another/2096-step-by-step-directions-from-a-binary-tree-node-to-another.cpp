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
    
    TreeNode* lca(TreeNode* root, int &start, int &end, int &depth, 
        int &lcaDepth, int &startDepth, int &endDepth, string &ds, string &ans) {
        
        if (!root) return root;
        if (root->val == start) startDepth = depth;    
        if (root->val == end) endDepth = depth, ans = ds;

        depth++;
        ds += 'L';
        TreeNode* left = lca(root->left, start, end, depth, lcaDepth, startDepth, endDepth, ds, ans);
        ds.pop_back();

        ds += 'R';
        TreeNode* right = lca(root->right, start, end, depth, lcaDepth, startDepth, endDepth, ds, ans);
        ds.pop_back();        
        depth--;        

        if ((root->val == start || root->val == end)) {
            if (left || right) lcaDepth = depth;
            return root;
        };
       
        if (!left) return right;
        else if (!right) return left;
        else {
            lcaDepth = depth;
            return root;
        };
    };
    
    string getDirections(TreeNode* root, int start, int end) {
        int depth = 0, lcaDepth = 0, startDepth = 0, endDepth = 0;
        string ds = "", ans = "";
        
        TreeNode* newRoot = lca(root, start, end, depth, lcaDepth, startDepth, endDepth, ds, ans);   
        
        ans = ans.substr(lcaDepth, endDepth - lcaDepth + 1);
        while (startDepth-- > lcaDepth) ans = "U" + ans;
        
        return ans;
    };
};