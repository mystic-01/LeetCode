class Solution {
public:
    const int offsets[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int row = grid1.size(), col = grid1[0].size(), validIslands = 0;
        queue<pair<int, int>> q;
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid2[i][j]) {
                    bool isSubIsland = true;

                    q.push({i, j});
                    grid2[i][j] = 0;
                    
                    while (!q.empty()) {
                        int x = q.front().first, y = q.front().second;
                        isSubIsland = isSubIsland && grid1[x][y];
                        q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int a = x + offsets[k][0], b = y + offsets[k][1];
                            if (a >= 0 && a < row && b >= 0 && b < col && grid2[a][b]) {
                                q.push({a, b});
                                grid2[a][b] = 0;                                    
                            };
                        };        
                    };
                    validIslands += isSubIsland;
                };
            };            
        };
        
        return validIslands;
    };
};