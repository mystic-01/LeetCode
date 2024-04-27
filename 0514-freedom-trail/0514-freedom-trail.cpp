static const int oob = 1e9;

class Solution {
public:
    int recurse(int idx, int kIdx, int &n, int &k, string &ring, string &key, int (*dp)[101]) {
        if (kIdx == k) {
            return 0;
        };
        if (dp[idx][kIdx] != -1) {
            return dp[idx][kIdx];    
        };
        
        int ans = oob;
        for (int i = idx; ; ++i) {
            int effectiveIndex = i % n, dist = abs(idx - effectiveIndex);
            if (ring[effectiveIndex] == key[kIdx]) {
                ans = min(ans, min(dist, abs(n - dist)) + recurse(effectiveIndex, kIdx + 1, n, k, ring, key, dp));
            };
            if (i != idx && effectiveIndex == idx) {
                break;    
            };
        };
        return dp[idx][kIdx] = ans;
    };
    
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), k = key.size(), dp[101][101];
        memset(dp, -1, sizeof(dp));
        return recurse(0, 0, n, k, ring, key, dp) + k;
    };
};