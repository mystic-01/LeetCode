class Solution {
public:
    bool recurse(int idx, string &s, unordered_set<string> &dict, int *dp) {
        if (idx == s.size()) return true;
        if (dp[idx] != -1) return dp[idx];
        for (int i = s.size() - idx; i > 0; i--) {
            if (dict.count(s.substr(idx, i))) {
                if (recurse(idx + i, s, dict, dp)) return true;    
            };
        };
        return dp[idx] = false;
    };
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size(), dp[size];
        for (int i = 0; i < size; i++) dp[i] = -1;
        unordered_set<string> dict;
        for (string &str : wordDict) dict.insert(str);
        return recurse(0, s, dict, dp);        
    };
};