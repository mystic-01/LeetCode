class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int n = s.size(), m = sub.size();
        unordered_map<char, unordered_set<char>> mp;
        for (vector<char> &vec : mappings) {
            mp[vec[0]].insert(vec[1]);    
        };        
        for (int i = 0; i + m <= n; ++i) {
            bool foundSubstr = true;
            for (int j = 0; j < m; ++j) {
                if (!(s[i + j] == sub[j] || mp[sub[j]].count(s[i + j]))) {
                    foundSubstr = false;
                    break;
                };
            };        
            if (foundSubstr) {
                return foundSubstr;
            };
        };
        return false;
    };
};