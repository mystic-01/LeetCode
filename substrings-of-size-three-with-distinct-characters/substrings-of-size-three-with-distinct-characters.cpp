class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.length() < 3) return 0;
        int i = 0, j = 1, k = 2, count = 0;
        while (k <= s.length() - 1) {
            if (s[i] != s[j] && s[j] != s[k] && s[k] != s[i]) count++;
            i++; j++; k++;
        }
        return count;
    };
};