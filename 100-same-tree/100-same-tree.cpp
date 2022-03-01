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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return 1;
        else if (!p || !q) return 0;
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);
        while (!q1.empty() && !q2.empty()) {
            int size1 = q1.size(), size2 = q2.size();
            if (size1 != size2) return 0;
            for (auto i = 0; i < size1; i++) {
                TreeNode* node1 = q1.front(), *node2 = q2.front();
                q1.pop(), q2.pop();
                if (!node1 && node2) return 0;
                if (node1 && !node2) return 0;
                if (node1 && node2 && node1->val != node2->val) return 0;
                if (node1) q1.push(node1->left), q1.push(node1->right);
                if (node2) q2.push(node2->left), q2.push(node2->right);
            };
        };
        return 1;
    };
};