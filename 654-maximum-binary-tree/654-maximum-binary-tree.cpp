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
    TreeNode* dfs(int start, int end, map<int, int>::iterator begin, map<int, int>::iterator it) {
        
        if (start > end) return nullptr;

        while (it->second < start || it->second > end) {
            it--;
            if (it == begin) return nullptr;
        };

        int val = it->first, idx = it->second;
        
        TreeNode* node = new TreeNode(val);        
        node->left = dfs(start, idx - 1, begin, it--);
        node->right = dfs(idx + 1, end, begin, it);
        
        return node;
    };
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        
        for (auto i = 0; i < n; i++) m[nums[i]] = i;
        auto it = m.end(), begin = m.begin();
        begin--, it--;
        
        return dfs(0, n, begin, it);
    };
};