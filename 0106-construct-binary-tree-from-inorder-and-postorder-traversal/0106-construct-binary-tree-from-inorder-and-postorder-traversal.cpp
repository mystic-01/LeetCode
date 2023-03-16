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
    TreeNode* build(int startIn, int endIn, vector<int>& inorder, int startPost, int endPost, 
        vector<int>& postorder, unordered_map<int, int>& m) {
        if (startIn > endIn || startPost < endPost) return nullptr;
        
        TreeNode* root = new TreeNode(postorder[startPost]);
        int idx = m[root->val];
        int numsLeft = endIn - idx;
        
        root->left = build(startIn, idx - 1, inorder, startPost - numsLeft - 1, endPost, postorder, m);
        root->right = build(idx + 1, endIn, inorder, startPost - 1, startPost - numsLeft, postorder, m);
        
        return root;
    };

    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = 0, n = inorder.size();
        unordered_map<int, int> m;        
        for (auto &i : inorder) m[i] = idx++;
        return build(0, n - 1, inorder, n - 1, 0, postorder, m);
    };
};