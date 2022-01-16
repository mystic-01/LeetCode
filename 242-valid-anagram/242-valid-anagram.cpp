class Solution {
public:
    bool isAnagram(string s, string t) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);     
        if (s.length() != t.length()) return 0;
        map<char, int> m;
        auto i = 0, j = 0;
        while (i < s.length()) {
            m[s[i++]]++;
            m[t[j++]]--;            
        };
        for (auto &k : m) if (k.second > 0) return 0;
        return 1;
    };
};