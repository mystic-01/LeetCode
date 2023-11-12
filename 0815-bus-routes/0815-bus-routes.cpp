class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < routes.size(); ++i) {
            for (int &x : routes[i]) {
                m[x].push_back(i);    
            };
        };
        int dist = 0;
        queue<int> q;
        unordered_set<int> vis;
        q.push(source);
        
        while (!q.empty()) {
            for (int i = 0, size = q.size(); i < size; ++i) {
                int node = q.front();
                q.pop();
                if (node == target) {
                    return dist;    
                };
                for (auto &val : m[node]) {
                    // 'val' is the ith row of routes we need to process now
                    if (!vis.count(val)) {
                        for (auto &num : routes[val]) {
                            q.push(num);
                        };
                        vis.insert(val);
                    };                
                };
            };
            ++dist;
        };
        
        return -1;
    };
};