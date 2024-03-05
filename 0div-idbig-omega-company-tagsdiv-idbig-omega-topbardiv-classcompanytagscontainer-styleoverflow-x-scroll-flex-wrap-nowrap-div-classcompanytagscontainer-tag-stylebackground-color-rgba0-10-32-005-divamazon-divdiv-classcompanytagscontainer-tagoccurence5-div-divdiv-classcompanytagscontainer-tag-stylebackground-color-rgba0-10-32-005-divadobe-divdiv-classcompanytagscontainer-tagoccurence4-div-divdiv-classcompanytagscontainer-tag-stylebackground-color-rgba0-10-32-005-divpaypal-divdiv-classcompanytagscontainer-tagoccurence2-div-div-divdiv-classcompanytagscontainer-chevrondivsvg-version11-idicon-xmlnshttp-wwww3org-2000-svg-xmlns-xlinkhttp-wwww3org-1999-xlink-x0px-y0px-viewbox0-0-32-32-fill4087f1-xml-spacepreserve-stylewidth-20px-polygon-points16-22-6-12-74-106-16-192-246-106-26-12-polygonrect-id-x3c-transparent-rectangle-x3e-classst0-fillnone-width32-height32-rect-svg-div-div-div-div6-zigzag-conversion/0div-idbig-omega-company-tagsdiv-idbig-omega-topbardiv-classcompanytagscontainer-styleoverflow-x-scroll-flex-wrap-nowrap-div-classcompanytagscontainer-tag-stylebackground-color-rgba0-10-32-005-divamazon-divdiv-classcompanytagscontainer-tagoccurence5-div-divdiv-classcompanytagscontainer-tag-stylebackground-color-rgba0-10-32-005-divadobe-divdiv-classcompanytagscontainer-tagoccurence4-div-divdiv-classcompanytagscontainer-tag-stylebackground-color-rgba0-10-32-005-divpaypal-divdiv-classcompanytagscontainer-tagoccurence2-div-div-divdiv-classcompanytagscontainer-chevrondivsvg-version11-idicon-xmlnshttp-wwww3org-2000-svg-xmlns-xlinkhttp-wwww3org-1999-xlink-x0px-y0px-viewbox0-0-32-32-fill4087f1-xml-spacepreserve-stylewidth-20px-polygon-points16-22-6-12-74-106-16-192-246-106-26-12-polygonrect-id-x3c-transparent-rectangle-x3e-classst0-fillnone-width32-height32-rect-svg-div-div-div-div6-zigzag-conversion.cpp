class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;    
        };
        
        int n = s.size();
        vector<vector<char>> dp(numRows);
        
        int idx = 0, offset = 1;
        for (int i = 0; i < n; ++i) {
            if (idx == numRows - 1) {
                offset = -1;
            } else if (idx == 0) {
                offset = 1;            
            };
            dp[idx].push_back(s[i]);
            idx += offset;
        };
        
        for (int i = 0, idx = 0; i < numRows; ++i) {
            for (int j = 0; j < dp[i].size(); ++j) {
                s[idx++] = dp[i][j];    
            };
        };
        return s;
    };
};