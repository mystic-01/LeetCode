class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double, int>>> adjList(n);
        
        for (auto i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back({succProb[i], edges[i][1]});    
            adjList[edges[i][1]].push_back({succProb[i], edges[i][0]});    
        };
        
        double dist[n];
        bool vis[n];
        
        for (auto i = 0; i < n; i++) dist[i] = 0, vis[i] = 0;
        dist[start] = 1.0;

        auto comp = [](pair<double, int> &p1, pair<double, int> &p2) {
            return p1.first < p2.first;      
        };
        
        priority_queue<pair<double, int>, vector<pair<double, int>>, decltype(comp)> pq(comp);
        
        pq.push({dist[start], start});
        
        while (!pq.empty()) {
            double wt = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if (!vis[idx]) {
                vis[idx] = 1;
                for (auto &[first, second] : adjList[idx]) {
                    if (first * wt > dist[second]) {
                        dist[second] = first * wt;
                        pq.push({dist[second], second});                    
                    };                
                };
            };
        };
        return dist[end];
    };
};