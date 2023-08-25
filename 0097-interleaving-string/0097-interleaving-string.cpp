int dp[201][201][201];

class Solution {
public:
    bool recurse(int idx1, int idx2, int idx3, string &s1, string &s2, string &s3, int (*dp)[201][201]) {
        if (idx1 == s1.size() && idx2 == s2.size() && idx3 == s3.size()) return dp[idx1][idx2][idx3] = 1;

        if (idx1 >= s1.size() && idx2 >= s2.size()) return dp[idx1][idx2][idx3] = 0;
    
        if (dp[idx1][idx2][idx3] != -1) return dp[idx1][idx2][idx3];
        
        bool take1 = 0;
        if (idx1 < s1.size() && s1[idx1] == s3[idx3]) take1 = recurse(idx1 + 1, idx2, idx3 + 1, s1, s2, s3, dp);
        if (take1) return dp[idx1][idx2][idx3] = take1;
        
        bool take2 = 0;
        if (idx2 < s2.size() && s2[idx2] == s3[idx3]) take2 = recurse(idx1, idx2 + 1, idx3 + 1, s1, s2, s3, dp);
        if (take2) return dp[idx1][idx2][idx3] = take2;
        
        bool notTake = recurse(idx1 + 1, idx2 + 1, idx3, s1, s2, s3, dp);
        if (notTake) return dp[idx1][idx2][idx3] = notTake;
            
        return dp[idx1][idx2][idx3] = take1 || take2 || notTake;
    };
    
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        
        for (int i = 0; i < 201; i++) {
            for (int j = 0; j < 201; j++) {
                for (int k = 0; k < 201; k++) {
                    dp[i][j][k] = -1;
                };        
            };        
        };
        
        return recurse(0, 0, 0, s1, s2, s3, dp);
    };
};


/*

"aabccaabccaabccaabccaabccaabccaabccaabccaabccaabccaabccaabccaabccaabccaabccaabccaabccaabccaabccaabcc"
"dbbcadbbcadbbcadbbcadbbcadbbcadbbcadbbcadbbcadbbcadbbcadbbcadbbcadbbcadbbcadbbcadbbcadbbcadbbcadbbca"
"aadbbcbcacaadbbcbcacaadbbcbcacaadbbcbcacaadbbcbcacaadbbcbcacaadbbcbcacaadbbcbcacaadbbcbcacaadbbcbcacaadbbcbcacaadbbcbcacaadbbcbcacaadbbcbcacaadbbcbcacaadbbcbcacaadbbcbcacaadbbcbcacaadbbcbcacaadbbcbcac"

*/