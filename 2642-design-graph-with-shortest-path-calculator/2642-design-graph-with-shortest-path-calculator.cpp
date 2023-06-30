class Graph {
private:
    int n = 0;
    vector<vector<pair<int, int>>> adjList;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
 
public:
    Graph(int &_n, vector<vector<int>>& edges) {
        n = _n;
        adjList.resize(n);
        for (auto &edge : edges) adjList[edge[0]].push_back({edge[1], edge[2]});    
    };
    
    void addEdge(vector<int> edge) {
        adjList[edge[0]].push_back({edge[1], edge[2]});    
    };
    
    int shortestPath(int node1, int node2) {
        int dist[n];
        // bool visited[n];   
        for (auto i = 0; i < n; i++) dist[i] = INT_MAX;
        dist[node1] = 0;
        pq.push({dist[node1], node1});
        
        while (!pq.empty()) {
            int wt = pq.top().first, idx = pq.top().second;
            pq.pop();
            // if (!visited[idx]) {
                // visited[idx] = 1;
                for (auto &[first, second] : adjList[idx]) {
                    if (wt + second < dist[first]) {
                        dist[first] = wt + second;
                        pq.push({dist[first], first});
                    };                                        
                };
            // };
        };
        
        return dist[node2] == INT_MAX ? -1 : dist[node2];                        
    };
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */