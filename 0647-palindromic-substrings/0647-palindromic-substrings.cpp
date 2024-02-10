class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for (int start = n - 1; start >= 0; --start) {
            for (int end = start; end < n; ++end) {
                if (start == end) {
                    dp[start][end] = 1;
                } else if (end == start + 1) {
                    dp[start][end] = (s[start] == s[end]);                    
                } else {
                    dp[start][end] = (s[start] == s[end]) ? dp[start + 1][end - 1] : 0;                                            
                };
                count += dp[start][end];
            };
        };

        return count;           
    };
};


// aaabaa
// 6 + 3 + 2 + 0 + 1