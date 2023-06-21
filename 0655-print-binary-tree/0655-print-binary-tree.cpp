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
private:
    int height(TreeNode* root) {
        return root ? 1 + max(height(root->left), height(root->right)) : 0;
    };
    
public:
    
    
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root), idx = 0;
        vector<vector<string>> ans(h, vector<string>(pow(2, h) - 1, ""));      
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, pow(2, --h) - 1});
        
        while (!q.empty()) {
            int size = q.size();
            for (auto i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                int pos = q.front().second;
                q.pop();
                ans[idx][pos] = to_string(node->val);
                if (node->left) q.push({node->left, pos - pow(2, h - 1)});
                if (node->right) q.push({node->right, pos + pow(2, h - 1)});
            };
            idx++, h--;
        };
        
        return ans;
    };
};

/*
int h = height(root);
vector<vector<tring>> ans(h, vector<string>(pow(2, h) - 1, ""));


[["","","","","","","","1","","","","","","",""],
 ["","","","2","","","","","","","","3","","",""],
 ["","4","","","","4","","","","5","","","","5",""]]
 ["5","","5","","6","","6","","5","","5","","6","","6",]]
 
 
 [["","","","","","","","1","","","","","","",""],
 ["","","","2","","","","","","","","3","","",""],
 ["","4","","","","5","","","","6","","","","7",""],
 ["8","","","","","","","","","","","","","",""]]

root, pos, height
1, pow(2, h) - 1, h
2, pow

node, pos, padding
q.push({x, pow(2, h) - 1 + padding});

*/