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
    
    void addNode(TreeNode* root, vector<string> &ans, string ds) {
        // int initialSize = ds.size();
        ds += to_string(root->val);

        if (!root->left && !root->right) ans.push_back(ds);        
        
        ds += "->";
        // int charAdded = ds.size() - initialSize;
        
        if (root->left) addNode(root->left, ans, ds);       
        if (root->right) addNode(root->right, ans, ds);   
        
        // while (charAdded--) ds.pop_back();
    };
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string ds;
        if (root) addNode(root, ans, ds);
        return ans;
    };
};