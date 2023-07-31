int dp[1001][1001];

class Solution {
public:
    // longest (heaviest) common subsequence
    int recurse(int idx1, int idx2, string &s1, string &s2, int (*dp)[1001]) {
        if (idx1 == s1.size() || idx2 == s2.size()) return 0;
        
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];            
        
        int take = 0;
        if (s1[idx1] == s2[idx2]) take = int(s1[idx1]) + recurse(idx1 + 1, idx2 + 1, s1, s2, dp);
        
        int notTake1 = recurse(idx1 + 1, idx2, s1, s2, dp);
        int notTake2 = recurse(idx1, idx2 + 1, s1, s2, dp);

        return dp[idx1][idx2] = max(take, max(notTake1, notTake2));
    };
    
    int minimumDeleteSum(string &s1, string &s2) {
        int n1 = s1.size(), n2 = s2.size(), sum = 0;
        
        for (char &ch1 : s1) sum += int(ch1);
        for (char &ch2 : s2) sum += int(ch2);
                
        for (int i = 0; i < 1001; i++) {
            for (int j = 0; j < 1001; j++) {
                dp[i][j] = -1;
            };        
        };
        
        return sum - 2 * recurse(0, 0, s1, s2, dp);
    };
};