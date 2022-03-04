// Hey, future self. Hope you're utilising your time on this planet well. 
// So, are you smart enough to do this using dfs now?
// 4 - 3 2022 Ans. Yes

class Solution {
public:
    void dfs(TreeNode* root, int level, vector<int>& ans) {
        if (!root) return;
        if (level == ans.size()) ans.push_back(root->val);
        dfs(root->right, level + 1, ans);
        dfs(root->left, level + 1, ans);
    };
    
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        dfs(root, 0, ans);        
        return ans;
    };
    // // BFS
    // vector<int> rightSideView(TreeNode* root) {
    //     if (!root) return {};
    //     vector<int> ans;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while (!q.empty()) {
    //         int size = q.size();
    //         for (auto i = 0; i < size; i++) {
    //             if (q.front()->left) q.push(q.front()->left);
    //             if (q.front()->right) q.push(q.front()->right);
    
    //             if (i == size - 1) ans.push_back(q.front()->val);
    //             q.pop();
    //         };
    //     };
    //     return ans;
    // };
};














