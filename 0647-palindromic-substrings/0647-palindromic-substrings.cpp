class Solution {
public:
    bool checkPalindrome(int &start, int &end, string &s, vector<vector<int>> &dp) {
        if (dp[start][end] != -1) { 
            return dp[start][end];
        };
        int st = start, en = end;
        while (st < en && s[st] == s[en]) {
            ++st, --en;
        };
        return dp[start][end] = st >= en;
    };

    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        for (int start = 0; start < n; ++start) {
            for (int end = start; end < n; ++end) {
                count += checkPalindrome(start, end, s, dp);
            };
        };

        return count;           
    };
};