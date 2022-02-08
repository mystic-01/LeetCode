class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        string s2 = s + s;
        for (auto i = 1; i < n; i++) if (s == s2.substr(i, n)) return 1;
        return 0;
    };
};