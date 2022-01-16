class Solution {
public:
    bool isAnagram(string s, string t) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);     
        if (s.length() != t.length()) return 0;
        map<char, int> m;
        for (auto &i : s) m[i]++;
        for (auto &j : t) m[j]--;
        for (auto &k : m) if (k.second > 0) return 0;
        return 1;
    };
};