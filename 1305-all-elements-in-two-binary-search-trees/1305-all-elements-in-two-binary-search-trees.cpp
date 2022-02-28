class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);        
    };
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1, tree2;
        dfs(root1, tree1);        
        dfs(root2, tree2);
        int l1 = tree1.size(), l2 = tree2.size();
        int i = l1 - 1, j = l2 - 1, k = l1 + l2 - 1;
        tree1.resize(l1 + l2);
        
        while(i >= 0 && j >= 0) tree1[k--] = (tree1[i] > tree2[j]) ? tree1[i--] : tree2[j--];            
        while(j >= 0) tree1[k--] = tree2[j--];            
        return tree1;
    };
};