class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size(), idx = -1, best = INT_MAX;
        
        for (auto i = 0; i < n; i++) {
            if (x == points[i][0] || y == points[i][1]) {
                int dist = abs(x - points[i][0]) + abs(y - points[i][1]);
                if (dist < best) best = dist, idx = i;
            };
        };
        
        return idx;
    };
};