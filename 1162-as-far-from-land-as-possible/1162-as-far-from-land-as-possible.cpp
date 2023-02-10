class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<pair<int, int>> v;
        int n = grid.size(), best = 0;
        
        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) {
                if (grid[i][j]) v.push_back({i, j});
            };
        }; 
        
        if (!v.size() || v.size() == (n * n)) return -1;
        
        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) {
                if (!grid[i][j]) {
                    int dist = INT_MAX;
                    for (auto &loc : v) dist = min(dist, abs(loc.first - i) + abs(loc.second - j));
                    best = max(best, dist);
                };
            };
        }; 
        return best;
    };
};