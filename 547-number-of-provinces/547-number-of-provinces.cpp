class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), count = 0;
        vector<vector<int>> edges(n);
        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) {
                if (j != i && isConnected[i][j]) {
                    edges[i].push_back(j);
                };
            };
        };
        vector<int> visited(n);
        for (auto i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                queue<int> q;
                q.push(i);
                visited[i] = 1;
                while(!q.empty()) {
                    int node = q.front(); q.pop();
                    for (auto &x : edges[node]) {
                        if (!visited[x]) q.push(x), visited[x] = 1;    
                    };
                };
            };
        };
        return count;
    };
};