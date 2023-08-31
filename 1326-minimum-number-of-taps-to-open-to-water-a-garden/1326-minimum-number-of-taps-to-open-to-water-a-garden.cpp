class Solution {
public:
    int recurse(int idx, int start, int &n, vector<int> &ranges, vector<vector<int>> &dp) {
        // cout << idx << " " << start << "\n";
        if (start >= n) return 0;
        if (idx == n + 1) return 1e5;        
        
        if (dp[idx][start + 1] != -1) return dp[idx][start + 1];
            
        int take = 1e5, notTake = 1e5;
        
        int lo = max(0, idx - ranges[idx]), hi = min(n, idx + ranges[idx]);
            
        if (ranges[idx] && lo <= start + 1 && hi > start) take = 1 + recurse(idx + 1, hi, n, ranges, dp);
        if (lo <= start + 1) notTake = recurse(idx + 1, start, n, ranges, dp);
        
        
        cout << idx << " : " << take << ", " << notTake << "\n";
        
        return dp[idx][start + 1] = min(take, notTake);        
    };
    
    int minTaps(int n, vector<int>& A) {
        vector<int> dp(n + 1, n + 2);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i)
            for (int j = max(i - A[i] + 1, 0); j <= min(i + A[i], n); ++j)
                dp[j] = min(dp[j], dp[max(0, i - A[i])] + 1);
        return dp[n]  < n + 2 ? dp[n] : -1;
    }
};


/*

15
[1,0,4,0,4,1,4,3,1,1,1,2,1,4,0,5]

0 - (0, 1)
1 - ()
2 - (0, 6)
3 - ()
4 - (0, 8)
5 - (4, 6)
6 - (2, 10)
7 - (4, 10)
8 - (7, 9)
9 - (8, 10)
10 - (9, 11)
11 - (9, 13)
12 - (11, 13)
13 - (9, 17)
14 - ()
15 - (10, 20)


0 2 4   7 8  9  10 11
8 10 10 9 10 17 20 13

*/