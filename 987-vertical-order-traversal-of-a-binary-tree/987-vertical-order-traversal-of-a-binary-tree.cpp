class Solution {
public:
    struct triplet {
        TreeNode* node;
        int vertical;
        int level;
        triplet (TreeNode* curr, int y, int x) {
            vertical = y, level = x, node = curr;           
        };
    };
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // y, x, val
        map<int, map<int, multiset<int>>> m;
        queue<triplet> q;
        q.push(triplet(root, 0, 0));
            
        while (!q.empty()) {
            int size = q.size();
            for (auto i =  0; i < size; i++) {
                TreeNode* curr = q.front().node;     
                int y = q.front().vertical, x = q.front().level;  
                q.pop();
                if (curr->left) q.push(triplet(curr->left, y - 1, x + 1));
                if (curr->right) q.push(triplet(curr->right, y + 1, x + 1));
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