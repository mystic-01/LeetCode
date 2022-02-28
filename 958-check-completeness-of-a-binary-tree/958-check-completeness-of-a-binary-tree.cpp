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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return false;
        queue<TreeNode*> q;
        q.push(root);
        
        int nullptrs = 0;
        while (!q.empty()) {
            int size =  q.size();
            for (auto i = 0; i < size; i++) {
                if (q.front()) {
                    if (nullptrs) return false;
                    q.push(q.front()->left);  
                    q.push(q.front()->right);  
                } else {
                    nullptrs++;
                };
                q.pop();
            };
        };
        return true;
    };
};