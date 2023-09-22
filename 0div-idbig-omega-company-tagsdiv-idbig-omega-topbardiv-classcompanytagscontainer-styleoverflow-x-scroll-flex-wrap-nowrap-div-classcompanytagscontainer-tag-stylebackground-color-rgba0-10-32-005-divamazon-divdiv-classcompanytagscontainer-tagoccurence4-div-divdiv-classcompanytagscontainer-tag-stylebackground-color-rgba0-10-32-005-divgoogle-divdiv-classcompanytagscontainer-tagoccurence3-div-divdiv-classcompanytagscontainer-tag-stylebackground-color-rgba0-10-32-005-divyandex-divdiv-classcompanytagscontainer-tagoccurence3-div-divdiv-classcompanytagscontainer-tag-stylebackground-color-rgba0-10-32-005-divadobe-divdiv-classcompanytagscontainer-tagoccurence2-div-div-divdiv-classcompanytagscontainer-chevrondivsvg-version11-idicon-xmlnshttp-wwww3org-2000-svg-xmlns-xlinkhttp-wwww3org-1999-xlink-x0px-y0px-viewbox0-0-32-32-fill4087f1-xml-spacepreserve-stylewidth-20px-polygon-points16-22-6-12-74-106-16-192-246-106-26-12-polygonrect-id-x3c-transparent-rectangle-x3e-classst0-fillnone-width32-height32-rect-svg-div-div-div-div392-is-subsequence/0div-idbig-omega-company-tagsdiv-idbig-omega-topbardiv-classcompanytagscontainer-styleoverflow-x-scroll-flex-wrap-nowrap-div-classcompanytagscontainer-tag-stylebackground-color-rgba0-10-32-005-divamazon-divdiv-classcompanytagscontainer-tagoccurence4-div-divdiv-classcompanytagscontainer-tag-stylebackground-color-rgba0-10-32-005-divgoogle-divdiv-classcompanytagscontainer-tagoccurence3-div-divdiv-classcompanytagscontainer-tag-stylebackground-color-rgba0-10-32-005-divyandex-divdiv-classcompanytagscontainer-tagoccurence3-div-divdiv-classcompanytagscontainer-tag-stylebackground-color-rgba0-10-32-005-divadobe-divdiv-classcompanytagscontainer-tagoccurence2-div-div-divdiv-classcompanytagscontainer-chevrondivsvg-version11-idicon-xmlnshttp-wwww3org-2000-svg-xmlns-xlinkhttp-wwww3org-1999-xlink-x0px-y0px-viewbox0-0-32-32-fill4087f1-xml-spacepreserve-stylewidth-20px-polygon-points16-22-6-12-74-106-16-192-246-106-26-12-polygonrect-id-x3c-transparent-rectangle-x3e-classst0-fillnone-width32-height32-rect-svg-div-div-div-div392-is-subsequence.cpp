class Solution {
public:
    bool recurse(int i, int j, string &child, string &parent, int (*dp)[101]) {
        if (i >= child.size()) return 1;
        else if (j >= parent.size()) return 0;        
        
        if (dp[j][i] != -1) return dp[j][i]; 
        
        bool take = 0, notTake = 0;
        if (child[i] == parent[j]) take = recurse(i + 1, j + 1, child, parent, dp);
        notTake = recurse(i, j + 1, child, parent, dp);
        
        return dp[j][i] = take || notTake;
    };
    
    bool isSubsequence(string s, string t) {
        int tSize = t.size(), dp[tSize + 1][101];                
        
        for (int i = 0; i < tSize + 1; i++) {
            for (int j = 0; j < 101; j++) {
                dp[i][j] = -1;
            };            
        };
        
        return recurse(0, 0, s, t, dp);
    };
};