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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (!root) return root;
        if (depth == 1) return new TreeNode(val, root, nullptr);
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
            
        while (!q.empty() && level < depth - 1) {
            level++;
            int size = q.size();
            for (auto i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (level == depth - 1) {
                    TreeNode* currL = curr->left, * currR = curr->right;
                    curr->left = new TreeNode(val, currL, nullptr);
                    curr->right = new TreeNode(val, nullptr, currR);                        
                } else { 
                    if (curr->left) q.push(curr->left);
                    if (curr->right) q.push(curr->right);
                };                
            };
        };  
        return root;
    };
};