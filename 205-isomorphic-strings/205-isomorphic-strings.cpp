class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        int n = s.size();
        for (auto i = 0; i < n; i++) {
            if (m.find(s[i]) == m.end()) m[s[i]] = t[i];
            else if (m.find(s[i])->second != t[i]) return false;
        };
        m = unordered_map<char, char>();
        for (auto i = 0; i < n; i++) {
            if (m.find(t[i]) == m.end()) m[t[i]] = s[i];
            else if (m.find(t[i])->second != s[i]) return false;
        };
        return true;
    };
};