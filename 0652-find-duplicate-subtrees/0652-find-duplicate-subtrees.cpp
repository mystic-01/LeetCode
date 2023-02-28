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
    string buildLeafToRootPathsMap(map<string, pair<TreeNode*, int>> &m, TreeNode* root) {
        if (!root) return "X";
        string s = "(" + to_string(root->val) + "->" + buildLeafToRootPathsMap(m, root->left) 
            + "->" + buildLeafToRootPathsMap(m, root->right) + ")";
        if (m.find(s) != m.end()) m[s] = {root, 2};
        else m[s] = {root, 1};
        return s;
    };
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, pair<TreeNode*, int>> m;
        vector<TreeNode*> dupes;
        buildLeafToRootPathsMap(m, root);
        
        for (auto &i : m) if (i.second.second > 1) dupes.push_back(i.second.first);
        return dupes;
    };
};











