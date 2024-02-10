class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), count = 0, dp[n + 1], prev[n + 1];
        fill(dp, dp + n + 1, 0);
        fill(prev, prev + n + 1, 0);
        
        for (int start = n - 1; start >= 0; --start) {
            for (int end = start; end < n; ++end) {
                if (start == end) {
                    dp[end] = 1;
                } else if (end == start + 1) {
                    dp[end] = (s[start] == s[end]);                    
                } else {
                    dp[end] = (s[start] == s[end]) ? prev[end - 1] : 0;                                            
                };
                count += dp[end];
            };
            for (int i = 0; i < n + 1; ++i) {
                prev[i] = dp[i];
            };
        };

        return count;           
    };
};
