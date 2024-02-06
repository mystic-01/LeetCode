class Solution {
public:
    bool isPalindrome(int start, int end, string &s) {
        while (start < end && s[start] == s[end]) {
            ++start, --end;
        };
        return start >= end;
    };
    
    int countMinPartitions(int idx, int end, string &s, int *dp) {
        if (idx > end) {
            return 0;
        };
        if (dp[idx] != -1) {
            return dp[idx];
        };
        
        int count = INT_MAX;
        for (int i = end; i >= idx; --i) {
            if (isPalindrome(idx, i, s)) {
                count = min(count, 1 + countMinPartitions(i + 1, end, s, dp));                    
            };
        };
        return dp[idx] = count;
    };
    
    int minCut(string s) {
        int n = s.size(), dp[n];
        fill(dp, dp + n, -1);
        return countMinPartitions(0, n - 1, s, dp) - 1;
    };
};