static int mod = 1e9 + 7;

class Solution {
public:
    int recurse(int curr, int &n, int *dp) {
        if (curr >= n) return dp[curr] = 0;
        if (dp[curr] != -1) return dp[curr];
        
        int ans = 1;
        ans = (ans + recurse(curr + 2, n, dp)) % mod;
        ans = (ans + recurse(curr + 1, n, dp)) % mod;
        
        return dp[curr] = ans;
    };
    
    int countHousePlacements(int n) {
        int dp[n + 2]; 
        long permutationsOnOneSide = 0, ans = 1; // empty streets == 1
        fill(dp, dp + n + 1, -1);
        
        permutationsOnOneSide = recurse(0, n, dp) % mod;
        ans = (ans + permutationsOnOneSide) % mod;
        ans = (ans + permutationsOnOneSide) % mod;
        permutationsOnOneSide = (permutationsOnOneSide * permutationsOnOneSide) % mod;
        ans = (ans + permutationsOnOneSide) % mod;
        return ans;
    };
};