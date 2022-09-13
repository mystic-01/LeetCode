/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> qOriginal, qCloned;
        qOriginal.push(original), qCloned.push(cloned);
        
        while (!qOriginal.empty()) {
            int size = qOriginal.size();
            for (auto i = 0; i < size; i++) {
                original = qOriginal.front(), cloned = qCloned.front();
                qOriginal.pop(), qCloned.pop();
                
                if (target == original) return cloned;
                if (original->left) qOriginal.push(original->left), qCloned.push(cloned->left);
                if (original->right) qOriginal.push(original->right), qCloned.push(cloned->right);
            };
        };
        
        return nullptr;
    };
};