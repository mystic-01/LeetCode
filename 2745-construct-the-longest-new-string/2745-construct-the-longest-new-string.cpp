class Solution {
public:
    int dp[51][51][51][4] = {};
    int solve(int x, int y, int z, int last){
        if(dp[x][y][z][last] != 0) return dp[x][y][z][last];
        int res = 0;
        if(x > 0 && last != 1){
            res = max(res, 2 + solve(x-1, y, z, 1));
        }
        if(y > 0 && last <= 1){
            res = max(res, 2 + solve(x, y-1, z, 2));
        }
        if(z > 0 && last != 1){
            res = max(res, 2 + solve(x, y, z-1, 3));
        }
        return dp[x][y][z][last] = res;
    }
    int longestString(int x, int y, int z) {
        return solve(x, y, z, 0);
    }
};