class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.length();
        vector<int> v(26);

        for (auto i = 0; i < n; i++) {
            v[t[i] - 'a']++;            
            v[s[i] - 'a']--;            
        };
        v[t[n] - 'a']++;            
        for (auto i = 0; i < 26; i++) if (v[i]) return 'a' + i;
        return 'a';
    };
};