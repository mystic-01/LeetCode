class Solution {
public:
    bool topoSort(int idx, vector<vector<int>> &adjList, int *visited) {
        visited[idx] = 1;
        
        for (auto &child : adjList[idx]) {
            if (visited[child] == 1) return false;    
            else if (visited[child] == 2) continue;
            else if (!topoSort(child, adjList, visited)) return false;
        };
        
        visited[idx] = 2;        
        return true;
    };
    
    bool canFinish(int n, vector<vector<int>>& graph) {
        vector<vector<int>> adjList(n);
        int visited[n];
        
        for (auto &vec : graph) adjList[vec[0]].push_back(vec[1]);    
        for (auto i = 0; i < n; i++) visited[i] = 0;

        for (auto i = 0; i < n; i++) if (!visited[i] && !topoSort(i, adjList, visited)) return false;
        
        return true;
    };
};