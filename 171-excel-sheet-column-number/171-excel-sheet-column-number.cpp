class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length(), ans = 0;
        for (auto i = 0; i < n; i++) {
            ans += (((s[i] - 'A') + 1) * pow(26, n - i - 1));
        };
        return ans;
    };
};