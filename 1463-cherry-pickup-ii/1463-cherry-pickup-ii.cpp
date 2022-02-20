class Solution {
public:
//     int pickup(int i, int j1, int j2, int m, int n, vector<vector<int>> grid, vector<vector<vector<int>>>& dp) {
//         if (j1 < 0 || j1 == n || j2 < 0 || j2 == n) return -1e7;
//         if (i == m) return 0;
//         if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
//         int res = -1e7;
//         for (auto dj1 = -1; dj1 <= 1; dj1++) {
//             for (auto dj2 = -1; dj2 <= 1; dj2++) {
//                 if (j1 == j2) {
//                     res = max(res, grid[i][j1] + pickup(i + 1, j1 + dj1, j2 + dj2, m, n, grid, dp));
//                 } else {
//                     res = max(res, grid[i][j1] + grid[i][j2] + pickup(i + 1, j1 + dj1, j2 + dj2, m, n, grid, dp));
//                 };
//             };
//         };
//         return dp[i][j1][j2] = res;
//     };
    
//     int cherryPickup(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size(), ans = -1e7; 
//         vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
        
//         auto i = m - 1;
//         for (auto j1 = 0; j1 < n; j1++) {
//             for (auto j2 = 0; j2 < n; j2++) {
//                 if (j1 == j2) dp[i][j1][j2] = grid[i][j1];
//                 else dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
//             };
//         };
        
//         for (auto i = m - 2; i >= 0; i--) {
//             for (auto j1 = 0; j1 < n; j1++) {
//                 for (auto j2 = 0; j2 < n; j2++) {
//                     int res = -1e7;
//                     for (auto dj1 = -1; dj1 <= 1; dj1++) {
//                         for (auto dj2 = -1; dj2 <= 1; dj2++) {
//                             if (j1 + dj1 >= 0 && j1 + dj1 < n && j2 + dj2 >= 0 && j2 + dj2 < n) {
//                                 if (j1 == j2) {
//                                     res = max(res, grid[i][j1] + dp[i + 1][j1 + dj1][j2 + dj2]);
//                                 } else {
//                                     res = max(res, grid[i][j1] + grid[i][j2] + dp[i + 1][j1 + dj1][j2 + dj2]);
//                                 };
//                             };
//                         };
//                     };
//                     dp[i][j1][j2] = res;     
//                 };
//             };
//         };
//         return dp[0][0][n - 1];
//     };
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = -1e7; 
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        auto i = m - 1;
        for (auto j1 = 0; j1 < n; j1++) {
            for (auto j2 = 0; j2 < n; j2++) {
                if (j1 == j2) dp[j1][j2] = grid[i][j1];
                else dp[j1][j2] = grid[i][j1] + grid[i][j2];
            };
        };
        
        for (auto i = m - 2; i >= 0; i--) {
            vector<vector<int>> curr(n, vector<int>(n, 0));        
            for (auto j1 = 0; j1 < n; j1++) {
                for (auto j2 = 0; j2 < n; j2++) {
                    int res = -1e7;
                    for (auto dj1 = -1; dj1 <= 1; dj1++) {
                        for (auto dj2 = -1; dj2 <= 1; dj2++) {
                            if (j1 + dj1 >= 0 && j1 + dj1 < n && j2 + dj2 >= 0 && j2 + dj2 < n) {
                                if (j1 == j2) {
                                    res = max(res, grid[i][j1] + dp[j1 + dj1][j2 + dj2]);
                                } else {
                                    res = max(res, grid[i][j1] + grid[i][j2] + dp[j1 + dj1][j2 + dj2]);
                                };
                            };
                        };
                    };
                    curr[j1][j2] = res;     
                };
            };
            dp = curr;
        };
        return dp[0][n - 1];
    };
};