class Solution {
public:
    string reverseStr(string s, int k) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    
        int j = 1, pos = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            if (j % (2 * k) == 0) {
                reverse(s.begin() + pos, s.begin() + pos + k);
                pos = j;
            };
            j++;
        };
        reverse(s.begin() + pos, (n - pos >= k) ? s.begin() + pos + k : s.end());
        return s;
    };
};