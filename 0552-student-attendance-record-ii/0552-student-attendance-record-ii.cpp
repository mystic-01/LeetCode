static const int mod = 1e9 + 7;

class Solution {
public:
    int recurse(int idx, int aLeft, int l, int &n, int (*dp)[2][3]) {
        if (idx == n) {
            return 1;
        };
        if (dp[idx][aLeft][l] != -1) {
            return dp[idx][aLeft][l];    
        };
        int takeP = 0, takeA = 0, takeL = 0;
        takeP = recurse(idx + 1, aLeft, 0, n, dp) % mod;
        if (aLeft) {
            takeA = recurse(idx + 1, 0, 0, n, dp) % mod;
        };
        if (l < 2) {
            takeL = recurse(idx + 1, aLeft, l + 1, n, dp) % mod;            
        };
        
        takeP = (takeP + (long long)takeA) % mod;
        takeP = (takeP + (long long)takeL) % mod; 
        
        return dp[idx][aLeft][l] = takeP;
    };
    
    int checkRecord(int n) {
        int dp[n][2][3];
        memset(dp, -1, sizeof(dp));
        return recurse(0, 1, 0, n, dp);
    };
};