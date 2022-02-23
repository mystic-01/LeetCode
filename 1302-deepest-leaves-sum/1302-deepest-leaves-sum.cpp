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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        if (!root) return sum;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size(), curr = 0;
            for (auto i = 0; i < size; i++) {
                if (q.front()->left) q.push(q.front()->left);                
                if (q.front()->right) q.push(q.front()->right);   
                curr += q.front()->val;
                q.pop();
            };
            sum = curr;
        };
        return sum;
    };
};