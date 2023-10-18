class Solution {
public:
    void topoSort(int node, bool *visited, vector<vector<int>> &adjList, stack<int> &st, vector<int> &time) {
        visited[node] = 1;
        for (auto &child : adjList[node]) {
            if (!visited[child]) {
                topoSort(child, visited, adjList, st, time);
            };
        };        
        st.push(node);
    };

    
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adjList(n + 1);
        for (auto &v : relations) {
            adjList[v[0]].push_back(v[1]);
        };
        
        stack<int> st;
        bool visited[n + 1];
        for (int i = 1; i < n + 1; ++i) {
            visited[i] = 0;
        };
        for (int i = 1; i < n + 1; ++i) {
            if (!visited[i]) {
                topoSort(i, visited, adjList, st, time);
            };
        };
        
        time.insert(time.begin(), 0);
        int maxTime = time[1];
        vector<int> ans = time;        
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            for (auto &child : adjList[node]) {
                ans[child] = max(ans[child], ans[node] + time[child]);
            };
        };
        for (int i = 1; i < n + 1; ++i) {
            maxTime = max(maxTime, ans[i]);
        };
        return maxTime;
    };
};
