class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), count = 0;
        vector<int> visited(n);
        for (auto i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                queue<int> q;
                q.push(i);
                visited[i] = 1;
                while(!q.empty()) {
                    int node = q.front(); q.pop();
                    for (auto x = 0; x < n; x++) {
                        if (isConnected[x][node] && !visited[x]) 
                            q.push(x), visited[x] = 1;    
                    };
                };
            };
        };
        return count;
    };
};