class Solution {
public:
    bool isPalindrome(int start, int end, string &s) {
        while (start < end && s[start] == s[end]) {
            ++start, --end;
        };
        return start >= end;
    };
    
    int minCut(string s) {
        int n = s.size(), dp[n + 1];
        fill(dp, dp + n, INT_MAX);
        dp[n] = 0;
        
        for (int idx = n - 1; idx >= 0; --idx) {
            for (int i = n - 1; i >= idx; --i) {
                if (isPalindrome(idx, i, s)) {
                    dp[idx] = min(dp[idx], 1 + dp[i + 1]);
                };
            };
        };
        
        return dp[0] - 1;
    };
};