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
    void findSecondSmallest(TreeNode *root, int &smallest, int &secondSmallest) {
        if (smallest == -1 || root->val == smallest) {
            smallest = root->val;
        } else if (root->val < smallest) {
            secondSmallest = smallest;
            smallest = root->val;
        } else if (secondSmallest == -1 || root->val < secondSmallest) {
            secondSmallest = root->val;                
        };
        
        if (root->left) findSecondSmallest(root->left, smallest, secondSmallest);
        if (root->right) findSecondSmallest(root->right, smallest, secondSmallest);
        
    };
    
    int findSecondMinimumValue(TreeNode* root) {
        int smallest = -1, secondSmallest = -1;
        findSecondSmallest(root, smallest, secondSmallest);
        return secondSmallest;
    };
};