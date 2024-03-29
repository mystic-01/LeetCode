class Solution {
int outOfBound = 1e5;
    
public:
    int recurse(int idx, int len, string &s, vector<string> &st, int (*dp)[52]) {
        if (idx == s.size()) return 0;
        if (idx + len > s.size()) return outOfBound;
        
        if (dp[idx][len] != -1) return dp[idx][len]; 
        
        int take = outOfBound, takeExtraLen = outOfBound, notTake = outOfBound;
            
        if (find(st.begin(), st.end(), s.substr(idx, len)) != st.end()) take = recurse(idx + len, 1, s, st, dp);
        takeExtraLen = recurse(idx, len + 1, s, st, dp);
        notTake = 1 + recurse(idx + 1, 1, s, st, dp);
        
        return dp[idx][len] = min({take, takeExtraLen, notTake});
    };
    
    int minExtraChar(string s, vector<string>& dictionary) {
        int dp[52][52];
        
        for (int i = 0; i < 52; i++) {
            for (int j = 0; j < 52; j++) {
                dp[i][j] = -1;
            };        
        };
        
        // set<string> st;
        // for (auto &str : dictionary) st.insert(str);
        // return recdictionaryurse(0, 1, s, st, dp);
        return recurse(0, 1, s, dictionary, dp);
    };
};