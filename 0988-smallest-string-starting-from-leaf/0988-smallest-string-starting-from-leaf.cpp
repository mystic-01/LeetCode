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
    void dfs(TreeNode* root, string &curr, string &ans) {
        if (!root) {
            return;
        };
        curr += ('a' + root->val);
        if (!root->left && !root->right) {
            reverse(begin(curr), end(curr));
            if (ans == "" || curr < ans) {
                ans = curr;                                
            };                        
            reverse(begin(curr), end(curr));
        };
        dfs(root->left, curr, ans);        
        dfs(root->right, curr, ans);        
        curr.pop_back();
    };
    
    string smallestFromLeaf(TreeNode* root) {
        string curr = "", ans = "";
        dfs(root, curr, ans);
        return ans;
    };
};