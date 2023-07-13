class Solution {
public:
    bool topoSort(int &idx, vector<vector<int>> &adjList, int *visited, vector<int> &ans) {
        visited[idx] = 1;
        for (auto &child : adjList[idx]) {
            if (visited[child] == 1) return false;
            else if (visited[child] == 2) continue;
            else if (!topoSort(child, adjList, visited, ans)) return false;
        };
        ans.push_back(idx);
        visited[idx] = 2;
        return true;
    };
    
    vector<int> findOrder(int n, vector<vector<int>>& graph) {
        vector<vector<int>> adjList(n);
        vector<int> ans;
        int visited[n];
        
        for (auto &vec : graph) adjList[vec[0]].push_back(vec[1]);
        for (int i = 0; i < n; i++) visited[i] = 0;
        for (int i = 0; i < n; i++) if (!visited[i] && !topoSort(i, adjList, visited, ans)) return {};

        return ans;
    };
};