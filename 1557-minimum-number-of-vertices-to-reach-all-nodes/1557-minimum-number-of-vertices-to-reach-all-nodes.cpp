class Solution {
public:
    void topoSort(int &node, vector<vector<int>> &adjList, int *visited, stack<int> &st, bool &isTopoSort) {
        for (auto &child : adjList[node]) {
            if (!visited[child]) {
                visited[child] = 1;
                topoSort(child, adjList, visited, st, isTopoSort); 
            };
        };        
        if (isTopoSort) st.push(node);
    };
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<int> ans;
        int visited[n];
        
        for (auto i = 0; i < n; i++) {
            visited[i] = 0;
        };
        
        for (auto &edge : edges) {
            adjList[edge[0]].push_back(edge[1]);                 
        };
        
        // Topo sort
        
        bool isTopoSort = true;
        stack<int> st;
        
        for (auto i = 0; i < n; i++) {
            if (!visited[i]) topoSort(i, adjList, visited, st, isTopoSort);
        };
        
        // Getting every node that visits a new node
        
        for (auto i = 0; i < n; i++) {
            visited[i] = 0;
        };
        
        isTopoSort = !isTopoSort;
        
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!visited[node]) {
                ans.push_back(node);
                topoSort(node, adjList, visited, st, isTopoSort);     
            };
        };
        return ans;  
    };
};