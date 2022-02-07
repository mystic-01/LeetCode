class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.length();
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (auto i = 0; i < n; i++) if (t[i] != s[i]) return t[i];
        return t[n];
    };
};