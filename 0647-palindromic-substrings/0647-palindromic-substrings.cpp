class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        
        for (int start = 0; start < n; ++start) {
            for (int end = start; end < n; ++end) {
                // if (dp[start][end] == -1) { 
                    int st = start, en = end;
                    while (st < en && s[st] == s[en]) {
                        ++st, --en;
                    };
                    count += st >= en;
                // };
                // count += dp[start][end];
            };
        };

        return count;           
    };
};