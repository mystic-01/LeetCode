class Solution {
public:
    bool isPalindrome(int start, int end, string &s, vector<vector<int>> &dpPartition) {
        if (dpPartition[start][end] != -1) {
            return dpPartition[start][end];    
        };
        while (start < end && s[start] == s[end]) {
            ++start, --end;
        };
        return dpPartition[start][end] = (start >= end);
    };
    
    int countMinPartitions(int idx, int end, string &s, int *dp, vector<vector<int>> &dpPartition) {
        if (idx > end) {
            return 0;
        };
        if (dp[idx] != -1) {
            return dp[idx];
        };
        
        int count = INT_MAX;
        for (int i = end; i >= idx; --i) {
            if (isPalindrome(idx, i, s, dpPartition)) {
                count = min(count, 1 + countMinPartitions(i + 1, end, s, dp, dpPartition));                    
            };
        };
        return dp[idx] = count;
    };
    
    int minCut(string s) {
        int n = s.size(), dp[n];
        fill(dp, dp + n, -1);
        vector<vector<int>> dpPartition(n, vector<int>(n, -1));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dpPartition[i][j] = -1;
            };        
        };
        return countMinPartitions(0, n - 1, s, dp, dpPartition) - 1;
    };
};