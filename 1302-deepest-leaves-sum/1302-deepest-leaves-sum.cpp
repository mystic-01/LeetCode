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
    int dfs(TreeNode* root, int depth, int& deepest, int& sum) {
        if (!root) return 0;
        if (!root->left && !root->right)
            if (depth == deepest) sum += root->val;
            else if (depth > deepest) sum = root->val, deepest = depth;
        
        dfs(root->left, depth + 1, deepest, sum);
        dfs(root->right, depth + 1, deepest, sum);
        return sum;
    };
    
    int deepestLeavesSum(TreeNode* root) {
//         int sum = 0;
//         if (!root) return sum;
//         queue<TreeNode*> q;
//         q.push(root);
        
//         while(!q.empty()) {
//             int size = q.size(), curr = 0;
//             for (auto i = 0; i < size; i++) {
//                 if (q.front()->left) q.push(q.front()->left);                
//                 if (q.front()->right) q.push(q.front()->right);   
//                 curr += q.front()->val;
//                 q.pop();
//             };
//             sum = curr;
//         };
        int deepest = 0, sum = 0;
        return dfs(root, 0, deepest, sum);
    };
};