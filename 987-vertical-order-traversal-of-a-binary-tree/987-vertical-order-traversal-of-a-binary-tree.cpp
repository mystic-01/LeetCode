
struct triplet {
    int vertical, level;
    TreeNode* node;
    triplet (int x, int y, TreeNode* _node) {
         vertical = y, level = x,  node = _node;
    };
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> points;
        if (!root) return ans;
        queue<triplet> q;
        q.push(triplet(0, 0, root));
        
        while (!q.empty()) {
            int size = q.size();
            for (auto i = 0; i < size; i++) {
                int y = q.front().vertical, x = q.front().level;
                
                TreeNode* node = q.front().node;
                points[y][x].insert(node->val);

                q.pop();
                if (node->left) q.push(triplet(x + 1, y - 1, node->left));
                if (node->right) q.push(triplet(x + 1, y + 1, node->right));
            };
        };
        
        for (auto &vertical : points) {
            vector<int> ds;
            for (auto &level : vertical.second) {
                for (auto &i : level.second) {
                    ds.push_back(i);
                };
            };
            ans.push_back(ds);
        };
        return ans;
    };
};