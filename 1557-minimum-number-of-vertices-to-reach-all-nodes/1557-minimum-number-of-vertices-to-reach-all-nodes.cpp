class Solution {
public:
    void topoSort(int &node, vector<vector<int>> &adjList, vector<int> &visited, stack<int> &st, bool &isTopoSort) {
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
        vector<int> visited(n, 0), ans;
        
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
        
        visited = vector<int>(n, 0);
        isTopoSort = !isTopoSort;
        
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            // cout << node << "\n";
            if (!visited[node]) {
                ans.push_back(node);
                topoSort(node, adjList, visited, st, isTopoSort);     
            };
        };
        // cout << "\n";
        return ans;  
    };
};