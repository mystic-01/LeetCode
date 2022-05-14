class Solution {
public:
    struct Comp {
        bool operator()(pair<int, int> p1, pair<int, int> p2) {
            return p1.first < p2.first;
        };
    };
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distance(n + 1, INT_MAX);
        vector<int> visited(n + 1, 0);
        vector<vector<pair<int, int>>> edges(n + 1);
        int size = times.size(), maxTime = INT_MIN;
        
        for (auto i = 0; i < size; i++)
            edges[times[i][0]].push_back({times[i][2], times[i][1]});     
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
        pq.push({0, k});
        distance[k] = 0;
        
        while (!pq.empty()) {
            int dist = pq.top().first, node = pq.top().second;
            pq.pop();
            // if (!visited[node]) {
                for (auto x : edges[node]) {
                    if (x.first + dist < distance[x.second]) {
                        distance[x.second] = dist + x.first;
                        pq.push({distance[x.second], x.second});                
                    };
                };
            // };
            visited[node] = 1;
        };
        for (auto i = 1; i < n + 1; i++) 
            maxTime = max(maxTime, distance[i]);            
        return maxTime == INT_MAX ? -1 : maxTime;
    };
};
