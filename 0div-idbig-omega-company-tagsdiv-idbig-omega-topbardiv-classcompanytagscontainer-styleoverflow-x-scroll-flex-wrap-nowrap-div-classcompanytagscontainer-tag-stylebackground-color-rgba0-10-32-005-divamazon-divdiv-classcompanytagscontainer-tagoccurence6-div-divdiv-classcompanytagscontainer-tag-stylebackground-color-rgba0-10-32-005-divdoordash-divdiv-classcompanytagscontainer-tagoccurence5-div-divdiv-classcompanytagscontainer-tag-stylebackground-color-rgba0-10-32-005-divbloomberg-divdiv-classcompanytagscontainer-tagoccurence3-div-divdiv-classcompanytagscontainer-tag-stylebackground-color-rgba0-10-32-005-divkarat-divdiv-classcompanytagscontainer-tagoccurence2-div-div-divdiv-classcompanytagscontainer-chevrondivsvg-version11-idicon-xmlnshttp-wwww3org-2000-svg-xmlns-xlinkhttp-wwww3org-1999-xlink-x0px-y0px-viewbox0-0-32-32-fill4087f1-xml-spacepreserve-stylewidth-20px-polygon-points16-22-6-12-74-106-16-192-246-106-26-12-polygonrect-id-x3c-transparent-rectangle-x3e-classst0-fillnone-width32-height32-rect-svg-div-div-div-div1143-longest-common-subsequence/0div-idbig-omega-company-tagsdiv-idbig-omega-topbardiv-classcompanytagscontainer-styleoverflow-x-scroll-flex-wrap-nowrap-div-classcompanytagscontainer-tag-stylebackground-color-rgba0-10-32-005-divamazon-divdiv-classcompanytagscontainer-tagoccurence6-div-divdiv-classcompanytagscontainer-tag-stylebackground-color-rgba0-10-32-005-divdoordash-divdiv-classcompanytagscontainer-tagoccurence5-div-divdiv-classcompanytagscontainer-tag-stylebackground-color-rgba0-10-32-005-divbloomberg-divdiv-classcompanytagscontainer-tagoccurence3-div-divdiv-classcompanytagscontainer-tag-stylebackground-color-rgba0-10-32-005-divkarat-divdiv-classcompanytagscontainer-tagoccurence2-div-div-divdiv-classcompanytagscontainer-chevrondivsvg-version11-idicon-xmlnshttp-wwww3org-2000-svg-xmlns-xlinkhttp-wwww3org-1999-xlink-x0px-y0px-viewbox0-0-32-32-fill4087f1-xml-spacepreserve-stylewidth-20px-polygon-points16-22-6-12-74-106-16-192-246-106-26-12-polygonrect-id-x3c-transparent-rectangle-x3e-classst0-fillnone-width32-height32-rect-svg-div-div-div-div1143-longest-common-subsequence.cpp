class Solution {
public:
//     int recurse(int idx1, int idx2, string &s1, string &s2, int (*dp)[1001]) {
//         if (idx1 == s1.size() || idx2 == s2.size()) return 0;
        
//         if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
//         int take = 0;
//         if (s1[idx1] == s2[idx2]) take = 1 + recurse(idx1 + 1, idx2 + 1, s1, s2, dp);
//         int notTake1 = recurse(idx1 + 1, idx2, s1, s2, dp);
//         int notTake2 = recurse(idx1, idx2 + 1, s1, s2, dp);
    
//         return dp[idx1][idx2] = max(take, max(notTake1, notTake2));
//     };
    
    int longestCommonSubsequence(string &s1, string &s2) {
        int dp[1001] = {0}, prev[1001] = {0};
        
        for (int idx1 = s1.size() - 1; idx1 >= 0; idx1--) {
            for (int idx2 = s2.size() - 1; idx2 >= 0; idx2--) {
                int take = (s1[idx1] == s2[idx2]) ? take = 1 + prev[idx2 + 1] : 0;
                int notTake1 = prev[idx2];
                int notTake2 = dp[idx2 + 1];
                
                dp[idx2] = max(take, max(notTake1, notTake2));
            };        
            for (int i = 0; i < 1001; i++) prev[i] = dp[i];
        };
        return dp[0];
    };
};