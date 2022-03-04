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
    TreeNode* constructTree(int startIn, int endIn, vector<int>& inorder, 
    int startPre, int endPre, vector<int>& preorder, unordered_map<int, int>& m) {
        
        if (startPre > endPre || startIn > endIn) return nullptr;
        TreeNode* root = new TreeNode(preorder[startPre]);
        int idx = m[root->val];
        int numsLeft = idx - startIn;
        
        root->left = constructTree(startIn, idx - 1, inorder, startPre + 1, numsLeft + startPre, preorder, m);
        root->right = constructTree(idx + 1, endIn, inorder, numsLeft + startPre + 1, endPre, preorder, m);
        return root;
    };

    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0, n = preorder.size();
        unordered_map<int, int> m;
        for (auto &i : inorder) m[i] = idx++;
        return constructTree(0, n - 1, inorder, 0, n - 1, preorder, m);
    };
};