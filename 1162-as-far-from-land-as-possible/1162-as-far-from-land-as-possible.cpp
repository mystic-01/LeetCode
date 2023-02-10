class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int v[10000][2] = {{}}, it = 0;
        int n = grid.size(), best = 0;
        
        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) {
                if (grid[i][j]) v[it][0] = i, v[it][1] = j, it++;
            };
        }; 
        
        if (!it || it == (n * n)) return -1;
        
        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) {
                if (!grid[i][j]) {
                    int dist = INT_MAX;
                    for (auto k = 0; k < it; k++) dist = min(dist, abs(v[k][0] - i) + abs(v[k][1] - j));
                    best = max(best, dist);
                };
            };
        }; 
        return best;
    };
};