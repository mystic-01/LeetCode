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
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         if (!root) return ans;
//         queue<TreeNode*> q;
//         q.push(root);
//         bool isReverse = false;
//         int level = 0;
//         while (!q.empty()) {
//             int size = q.size();
//             vector<int> ds(size);
//             for (auto i = 0; i < size; i++) {
//                 if (q.front()->left) q.push(q.front()->left);
//                 if (q.front()->right) q.push(q.front()->right);
                
//                 ds[level % 2 ? size - i - 1 : i] = (q.front()->val);
//                 q.pop();
//             };
//             ans.push_back(ds);
//             isReverse = !isReverse;
//             level++;
//         };
//         return ans;
//     };
// };

// True Zig Zag Level Order Traversal.

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        stack<TreeNode*> dqL, dqR;
        dqL.push(root);
        
        while (!dqL.empty() || !dqR.empty()) {
            vector<int> ds;
            while (!dqL.empty()) {
                TreeNode* curr = dqL.top();
                dqL.pop();
                ds.push_back(curr->val);
                if (curr->left) dqR.push(curr->left);
                if (curr->right) dqR.push(curr->right);
            };
            if (!ds.empty()) ans.push_back(ds), ds.clear();
                
            while (!dqR.empty()) {
                TreeNode* curr = dqR.top();
                dqR.pop();
                ds.push_back(curr->val);
                if (curr->right) dqL.push(curr->right);
                if (curr->left) dqL.push(curr->left);
            };
            
            if (!ds.empty()) ans.push_back(ds), ds.clear();            
        };
        return ans;
    };
};


