// Hey, future self. Hope you're not wasting your time. 
// So, are you smart enough to do this using dfs now?

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            for (auto i = 0; i < size; i++) {
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                
                if (i == size - 1) ans.push_back(q.front()->val);
                q.pop();
            };
        };
        return ans;
    };
};














