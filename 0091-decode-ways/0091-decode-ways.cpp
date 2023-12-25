class Solution {
public:
    int recurse(int idx, string &s, int *dp) {
        if (idx == s.size()) return 1;     
        if (s[idx] == '0') return 0;
        
        if (dp[idx] != -1) return dp[idx];
        
        int takeOne = 0, takeTwo = 0;
        takeOne = recurse(idx + 1, s, dp);
        if (idx + 1 < s.size() && stoi(s.substr(idx, 2)) <= 26) takeTwo = recurse(idx + 2, s, dp);
        
        return dp[idx] = takeOne + takeTwo;
    };
    
    int numDecodings(string s) {
        int n = s.size(), dp[n + 1];
        fill(dp, dp + n + 1, -1);
        return recurse(0, s, dp);
    };
};