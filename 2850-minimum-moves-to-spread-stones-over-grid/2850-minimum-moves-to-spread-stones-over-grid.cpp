class Solution {
public:
    bool containsNoZeros(vector<vector<int>> &grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) return false;
            };        
        };
        return true;
    };
    
    int recurse(int x, int y, vector<vector<int>> &grid) {
        if (containsNoZeros(grid)) return 0;      
        pair<int, int> coords;
        
        int dist = 2147483647, curr = 2147483647;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 1 && (abs(x - i) + abs(y - j) < dist)) dist = abs(x - i) + abs(y - j), coords = {i, j};
            };        
        };
        
        grid[coords.first][coords.second]--, grid[x][y]++;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) curr = min(curr, recurse(i, j, grid));
            };        
        };
        grid[coords.first][coords.second]++, grid[x][y]--;

        curr = curr == 2147483647 ? 0 : curr;
        return dist + curr;
    };
    
    int minimumMoves(vector<vector<int>>& grid) {
        int ans = 2147483647;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) ans = min(ans, recurse(i, j, grid));
            };        
        };
        return ans == 2147483647 ? 0 : ans;
    };
};


/*
0 1 1
2 0 3
0 1 1
*/