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
    pair<int, int> postorder(TreeNode *root, int &count) {
        if (!root) return {0, 0};
        
        pair<int, int> left = postorder(root->left, count);
        pair<int, int> right = postorder(root->right, count);
        
        int currSum = left.first + right.first + root->val;
        int currNodes = left.second + right.second + 1;
        
        if (root->val == currSum / currNodes) ++count;
        return {currSum, currNodes};
    };
    
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        postorder(root, count);
        return count;
    };
};