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
        int xorOfAll = 0;
        for (auto &vec : descriptions) {
            int parent = vec[0], child = vec[1], isLeft = vec[2];
            if (m.find(parent) == m.end()) {
                m[parent] = new TreeNode(parent);
                xorOfAll ^= parent;
            };
            if (m.find(child) == m.end()) {
                m[child] = new TreeNode(child);                
                xorOfAll ^= child;
            };
            if (isLeft) {
                m[parent]->left = m[child];            
            } else {
                m[parent]->right = m[child];                
            };
        };
        for (auto &vect : descriptions) {
            xorOfAll ^= vect[1];
        };
        return m[xorOfAll];        
    };
};