struct node {
    int idx, distance, color;
    node(int _idx, int _distance, int _color) {
        idx =_idx, distance = _distance, color = _color;
    };
};

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adjList(n);
        int dist[n][2];
        vector<int> ans(n);
         
        for (int i = 0; i < n; i++) {
            dist[i][0] = INT_MAX, dist[i][1] = INT_MAX;
        };
        
        for (auto &blueEdge : blueEdges) adjList[blueEdge[0]].push_back({blueEdge[1], 0});
        for (auto &redEdge : redEdges) adjList[redEdge[0]].push_back({redEdge[1], 1});
        
        auto comp = [](const node &n1, const node &n2) {
            return n1.distance > n2.distance;             
        };
        
        queue<node> q;
        
        
        dist[0][0] = 0, dist[0][1] = 0;
        q.emplace(node(0, 0, -1));
        
        while (!q.empty()) {
            int idx = q.front().idx, distance = q.front().distance, color = q.front().color;
            q.pop();
            
            for (auto &[first, second] : adjList[idx]) {
                if (distance + 1 < dist[first][second] && (color == -1 || second == !color)) {
                    dist[first][second] = distance + 1;
                    q.emplace(node(first, distance + 1, second));
                };
            };
        };
        
        for (int i = 0; i < n; i++) {
            ans[i] = min(dist[i][0], dist[i][1]);
            if (ans[i] == INT_MAX) ans[i] = -1;
        };
        return ans;
    };
};

/*

3
[[0,1],[1,2]]
[]
3
[[0,1]]
[[2,1]]
3
[[0,1],[0,2]]
[[1,0]]
5
[[0,1],[1,2],[2,3],[3,4]]
[[1,2],[2,3],[3,1]]

*/