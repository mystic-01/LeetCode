class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size(), chars[26], ans = n;
        fill(chars, chars + 26, -1);
        for (int i = 0; i < n; ++i) {
            chars[s[i] - 'a'] = (chars[s[i] - 'a'] == -1 ? i : -2);    
        };
        for (int i = 0; i < 26; ++i) {
            if (chars[i] >= 0) ans = min(ans, chars[i]);
        };
        return ans == n ? -1 : ans;
    };
};