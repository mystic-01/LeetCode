class Solution {
// Use Topo Sort!
            
    
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n), adjList(n);
        vector<set<int>> ansSet(n);
        
        vector<int> indegree(n, 0);
        queue<int> q;
        
        for (auto &edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        };
        
        for (auto i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);                
        };

        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto &child : adjList[node]) {
                if (--indegree[child] == 0) q.push(child);

                for (auto &x : ansSet[node]) ansSet[child].insert(x);
                ansSet[child].insert(node);
            };
        };
        
        int i = 0;
        for (auto &s : ansSet) {    
            for (auto &num : s) ans[i].push_back(num);
            i++;
        };
        
        return ans;
    };
};






