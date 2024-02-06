class Solution {
public:
    int minCut(string s) {
        int n = s.size(), dp[n + 1];
        fill(dp, dp + n, 1e5);
        dp[n] = 0;
        
        for (int idx = n - 1; idx >= 0; --idx) {
            for (int i = n - 1; i >= idx; --i) {
                int start = idx, end = i;
                while (start < end && s[start] == s[end]) {
                    ++start, --end;
                };
                if (start >= end) {
                    dp[idx] = min(dp[idx], 1 + dp[i + 1]);
                };
            };
        };
        return dp[0] - 1;
    };
};