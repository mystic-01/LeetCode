class Solution {
public:
    int equalSubstring(string s, string t, int cost) {
        int n = s.size(), left = 0, maxLen = 0;
        for (int i = 0; i < n; ++i) {
            cost -= abs(s[i] - t[i]);
            while (left < n && cost < 0) {
                cost += abs(s[left] - t[left]), ++left;     
            };
            maxLen = max(maxLen, i - left + 1);
        };
        return maxLen;
    };
};