class Solution {
public:
    bool dfs(int source, int &dest, vector<vector<int>>& adjList, bool *vis) {
        if (source == dest) return true;
        vis[source] = true;
        
        for (auto &child : adjList[source]) {
            if (!vis[child] && dfs(child, dest, adjList, vis)) return true;            
        };
        
        return false;
    };
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        bool vis[n];
        vector<vector<int>> adjList(n);
            
        for (int i = 0; i < n; i++) {
            vis[i] = false;
        };
        for (auto &vec : edges) {
            adjList[vec[0]].push_back(vec[1]);
            adjList[vec[1]].push_back(vec[0]);
        };        
        return dfs(source, dest, adjList, vis);        
    };
};