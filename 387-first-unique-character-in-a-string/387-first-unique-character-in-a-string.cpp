class Solution {
public:
    int firstUniqChar(string s) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);     
        vector<int> v(26);
        for (auto i : s) v[i - 'a']++;
        for (auto i = 0; i < s.length(); i++) if (v[s[i] - 'a'] == 1) return i;
        return -1;
    };
};