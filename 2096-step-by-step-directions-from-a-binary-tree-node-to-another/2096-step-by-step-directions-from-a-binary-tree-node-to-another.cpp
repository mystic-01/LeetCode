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
    int start, end, depth = 0, lcaDepth = 0, startDepth = 0, endDepth = 0;
    string ds = "", ans = "";
    
public:
    TreeNode* lca(TreeNode* root) {
        if (!root) return root;
        if (root->val == start) startDepth = depth;    
        else if (root->val == end) endDepth = depth, ans = ds;

        depth++;
        ds += 'L';
        TreeNode* left = lca(root->left);
        ds.pop_back();

        ds += 'R';
        TreeNode* right = lca(root->right);
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
    
    string getDirections(TreeNode* root, int &startVal, int &endVal) {
        start = startVal, end = endVal;
        lca(root);
        
        ans = ans.substr(lcaDepth, endDepth - lcaDepth + 1);
        while (startDepth-- > lcaDepth) ans = "U" + ans;
        
        return ans;
    };
};