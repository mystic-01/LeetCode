class Solution {
public:
    void updateStartAndEnd(int &j, int &k, string &s, int &n, int &start, int &end) {
        while (j >= 0 && k < n && s[j] == s[k]) {
            j--, k++;
        };
        if (k - j > end - start) end = k, start = j;                
    };
    
    void getMaxPalindromeLen(int &i, string &s, int &n, int &start, int &end) {
        if (i + 1 < n && s[i] == s[i + 1]) {
            int j = i, k = i + 1;
            updateStartAndEnd(j, k, s, n, start, end);
        };   
        if (i - 1 >= 0 && s[i] == s[i - 1]) {
            int j = i - 1, k = i;
            updateStartAndEnd(j, k, s, n, start, end);            
        };   
        if (i - 1 >= 0 && i + 1 < n && s[i - 1] == s[i + 1]) {
            int j = i - 1, k = i + 1;
            updateStartAndEnd(j, k, s, n, start, end);
        };   
        
    };
    
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, end = 0;
        for (int i = 0; i < n; ++i) {
            getMaxPalindromeLen(i, s, n, start, end);
        };
        return !start && !end ? s.substr(0, 1) : s.substr(start + 1, (end - 1) - (start + 1) + 1);
    };
};