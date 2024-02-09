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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        unordered_set<int> notParents;
        for (auto &vec : descriptions) {
            int parent = vec[0], child = vec[1], isLeft = vec[2];
            if (m.find(parent) == m.end()) {
                m[parent] = new TreeNode(parent);
            };
            if (m.find(child) == m.end()) {
                m[child] = new TreeNode(child);                
            };
            if (isLeft) {
                m[parent]->left = m[child];            
            } else {
                m[parent]->right = m[child];                
            };
            notParents.insert(child);
        };
        for (auto &vecAgain : descriptions) {
            int parent = vecAgain[0];
            if (notParents.count(parent) == 0) {
                return m[parent];    
            };
        };
        
        return nullptr;        
    };
};