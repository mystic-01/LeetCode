class Solution {
public:
//     struct triplet {
//         TreeNode* node;
//         int x;
//         int y;
//     };
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // y, x, val
        map<int, map<int, multiset<int>>> m;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
            
        while (!q.empty()) {
            int size = q.size();
            for (auto i =  0; i < size; i++) {
                TreeNode* curr = q.front().first;     
                int y = q.front().second.first, x = q.front().second.second;  
                q.pop();
                if (curr->left) q.push({curr->left, {y - 1, x + 1}});
                if (curr->right) q.push({curr->right, {y + 1, x + 1}});
                m[y][x].insert(curr->val);
            };
        };
        
        vector<vector<int>> ans;
        for (auto &y : m) {
            vector<int> ds;
            for (auto &x : y.second) {
                for (auto &num : x.second) {
                    ds.push_back(num);    
                };                
            };
            ans.push_back(ds);
        };
        return ans;
    };
};