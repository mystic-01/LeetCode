class Solution {
public:
    bool dfsDetectCycle(int node, vector<vector<int>>& edges, vector<int>& visited, vector<int>& dfsVisited) {
        visited[node] = 1, dfsVisited[node] = 1;
        for (auto &i : edges[node]) {
            if (!visited[i]) {
                if (dfsDetectCycle(i, edges, visited, dfsVisited)) return true;
            } else if (dfsVisited[i] == 1) return true;    
        };
        dfsVisited[node] = 0;
        return false;
    };
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(n);
        for (auto &it : prerequisites) edges[it[0]].push_back(it[1]);
        vector<int> visited(n, 0), dfsVisited(n, 0);

        for (auto i = 0; i < n; i++) {
            if (!visited[i]) {
                // We can not finish courses if they have a cycle.
                if (dfsDetectCycle(i, edges, visited, dfsVisited)) return false;    
            };
        };
        return true;
    };
};