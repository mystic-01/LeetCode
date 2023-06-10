class Solution {
private:
    int mod = 1e9 + 7;
    int dfs(int start, int target, int *dist, vector<vector<pair<int, int>>> &adjList, bool *pathVisited, int* dp) {
        int count = 0;
        if (start == target) return 1;

        for (auto &[first, second] : adjList[start]) {
            if (dist[start] > dist[first] && !pathVisited[first]) {
                
                if (dp[first] == -1) {
                    pathVisited[first] = 1;
                    dp[first] = dfs(first, target, dist, adjList, pathVisited, dp);
                    pathVisited[first] = 0;                
                };
                
                count = (count + dp[first]) % mod;
            };
        };
        return count;
    };

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        int dist[n + 1], dp[n + 1];
        bool pathVisited[n + 1];
        for (auto i = 1; i <= n; i++) dist[i] = INT_MAX, dp[i] = -1, pathVisited[i] = 0;
        
        vector<vector<pair<int, int>>> adjList(n + 1);
        for (auto &edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        };
        
        // {dist, idx};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, n});
        dist[n] = 0;
        
        while(!pq.empty()) {
            int node = pq.top().second, wt = pq.top().first;
            pq.pop();
            
            for (auto &child : adjList[node]) {
                int childNode = child.first, newDist = child.second + wt;
                if (newDist < dist[childNode]) {
                    dist[childNode] = newDist;
                    pq.push({newDist, childNode});
                };            
            };
        };
        
        pathVisited[1] = 1;
        return dfs(1, n, dist, adjList, pathVisited, dp);
    };
};