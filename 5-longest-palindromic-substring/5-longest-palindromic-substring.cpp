class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), i = 0, j = 0, len = 0, start = 0, end = 0;

        for (auto k = 0; k < n; k++) {
            
            i = k - 1, j = k + 1;
            while (i >= 0 && j < n && s[i] == s[j]) i--, j++;
            len = j - i - 1;
            if (len > end - start + 1) {
                start = k - ((len - 1) / 2);
                end = k + (len / 2);
            };
            
            i = k, j = k + 1;
            while (i >= 0 && j < n && s[i] == s[j]) i--, j++;
            len = j - i - 1;
            if (len > end - start + 1) {
                start = k - ((len - 1) / 2);
                end = k + (len / 2);
            };
        };
        return s.substr(start, end - start + 1);
    };
};