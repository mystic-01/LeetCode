int dp[501][501];


class Solution {
public:
    int recurse(int idx1, int idx2, string &s1, string &s2, int (*dp)[501]) {
        if (idx1 == s1.size() || idx2 == s2.size()) return 0;
        
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        int take = 0;
        if (s1[idx1] == s2[idx2]) take = 2 + recurse(idx1 + 1, idx2 + 1, s1, s2, dp);
        
        int notTake1 = recurse(idx1 + 1, idx2, s1, s2, dp);
        int notTake2 = recurse(idx1, idx2 + 1, s1, s2, dp);
        
        return dp[idx1][idx2] = max(take, max(notTake1, notTake2));
    };
    
    int minDistance(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        
        for (int i = 0; i < 501; i++) {
            for (int j = 0; j < 501; j++) {
                dp[i][j] = -1;
            };
        };
        
        return n1 + n2 - recurse(0, 0, s1, s2, dp);
    };
};