class Solution {
public:
    // longest (heaviest) common subsequence
    int recurse(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp) {
        if (idx1 == s1.size() || idx2 == s2.size()) return 0;
        
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];            
        
        int take = 0;
        if (s1[idx1] == s2[idx2]) take = int(s1[idx1]) + recurse(idx1 + 1, idx2 + 1, s1, s2, dp);
        
        int notTake1 = recurse(idx1 + 1, idx2, s1, s2, dp);
        int notTake2 = recurse(idx1, idx2 + 1, s1, s2, dp);

            
        return dp[idx1][idx2] = max(take, max(notTake1, notTake2));
    };
    
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(), sum = 0;
        
        for (auto &ch1 : s1) sum += int(ch1);
        for (auto &ch2 : s2) sum += int(ch2);
        
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        // cout << sum << " " << 2 * recurse(0, 0, s1, s2, dp) << "\n";
        // 115 116 97 97 202 -> 627 - 396
        
        return sum - 2 * recurse(0, 0, s1, s2, dp);
    };
};