class Solution {
public:
    bool isAnagram(string s, string t) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);     
        if (s.length() != t.length()) return 0;
        vector<int> v(26);
        for (auto i = 0; i < s.length(); i++) {
            v[s[i] - 'a']++;
            v[t[i] - 'a']--;            
        };
        for (auto k : v) if (k != 0) return 0;
        return 1;
    };
};