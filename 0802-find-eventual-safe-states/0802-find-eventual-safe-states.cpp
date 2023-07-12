class Solution {
public:
    bool checkIfParentFound(int node, vector<vector<int>>& graph, int *visited) {
        visited[node] = -1;
        
        for (int &child : graph[node]) {
            if (visited[child] == 1) continue;
            else if (visited[child] == -1) return false;
            else {
                if (!checkIfParentFound(child, graph, visited)) return false;
            };
        };
        
        visited[node] = 1;
        return true;
    };    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int visited[graph.size()];
        for (int i = 0; i < graph.size(); i++) visited[i] = 0;
         
        for (int i = 0; i < graph.size(); i++) {
            if (visited[i] == 0) checkIfParentFound(i, graph, visited);    
            if (visited[i] == 1) ans.push_back(i);
        };
        return ans;      
    };
};