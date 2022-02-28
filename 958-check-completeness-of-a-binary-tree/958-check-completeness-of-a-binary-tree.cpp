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
        
        int globalNullptrs = 0;
        while (!q.empty()) {
            int size =  q.size(), nullptrs = 0;
            for (auto i = 0; i < size; i++) {
                if (q.front()) {
                    if (nullptrs || globalNullptrs) return false;
                    q.push(q.front()->left);  
                    q.push(q.front()->right);  
                } else {
                    nullptrs++, globalNullptrs++;
                };
                q.pop();
            };
        };
        return true;
    };
};