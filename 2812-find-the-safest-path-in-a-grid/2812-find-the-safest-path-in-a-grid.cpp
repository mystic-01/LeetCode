struct triplet {
    int dist, x, y;
    
    triplet(int _dist, int _x, int _y) {
        dist = _dist, x = _x,  y = _y;        
    };
};

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int offsets[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        queue<triplet> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push(triplet(0, i, j));
                    grid[i][j] = -1;
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = 2147364847;
                };                 
            };
        };
        
        while (!q.empty()) {
            int x = q.front().x, y = q.front().y, dist = q.front().dist;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int a = x + offsets[k][0], b = y + offsets[k][1];    
                if (a < n && a >= 0 && b < n && b >= 0 && grid[a][b] > dist + 1) {
                    q.push(triplet(dist + 1, a, b));
                    grid[a][b] = dist + 1;
                };
            };
        };

        auto comp = [](const triplet &t1, const triplet &t2) {
            return t1.dist < t2.dist;            
        };
        
        priority_queue<triplet, vector<triplet>, decltype(comp)> pq;
        pq.push(triplet(grid[0][0], 0, 0));
        
        while (!pq.empty()) {
            int x = pq.top().x, y = pq.top().y, dist = pq.top().dist;
            pq.pop();
            if (x == n - 1 && y == n - 1) return dist;
            else {
                for (int k = 0; k < 4; k++) {
                    int a = x + offsets[k][0], b = y + offsets[k][1];    
                    if (a >= 0 && b >= 0 && a < n && b < n && grid[a][b] != -1) {
                        pq.push(triplet(min(dist, grid[a][b]), a, b));
                        grid[a][b] = -1;
                    };
                };
            };
        };
        
        return -1;
    };
};