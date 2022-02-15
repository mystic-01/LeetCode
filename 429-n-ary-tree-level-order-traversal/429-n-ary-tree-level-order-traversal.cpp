class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if(!root) return ans;
        q.push(root);
        
        while (!q.empty()) {
            vector<int> ds;
            int size = q.size();
            for (auto i = 0; i < size; i++) {
                ds.push_back(q.front()->val);
                for (auto j = 0; j < q.front()->children.size(); j++) q.push(q.front()->children[j]);
                q.pop();
            };
            ans.push_back(ds);
        };
        return ans;
    };
};