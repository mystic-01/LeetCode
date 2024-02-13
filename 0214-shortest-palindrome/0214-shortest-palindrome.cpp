class Solution {
public:
    void fillLpsTable(string &pattern, int *lps) {
        int i = 0, prev = 0, m = pattern.size();
        lps[i++] = 0;
        while (i < m) {
            if (pattern[i] == pattern[prev]) {
                lps[i] = prev + 1, i++, prev++;
            } else {
                if (prev == 0) {
                    lps[i] = 0, i++;
                } else {
                    prev = lps[prev - 1];    
                };    
            };    
        };
        // for (int i = 0; i < m; ++i) {
        //     cout << lps[i] << " ";    
        // };
        // cout << "\n";
    };
    
    string shortestPalindrome(string s) {
        if (s == "") {
            return s;    
        };
        int n = s.size(), lps[2 * n + 1], i = 0;
        string rev = s;
        reverse(begin(rev), end(rev));
        rev = s + "#" + rev;
        fillLpsTable(rev, lps);

        string toBeAddedToFront = s.substr(lps[2 * n]);
        reverse(begin(toBeAddedToFront), end(toBeAddedToFront));
        return toBeAddedToFront + s;
    };
};

// i : aaacecaa

// j : aacecaaa
// jMax = 7 - 1 = 6
// iMax = 8 - 1 = 7

// 0 1 0 0 0 1 2 2
//     zabaxyo
    
//     oyxabaz

//  rev + org
// "ababbabbbaba#ababbbabbaba"
//  org + rev
// "ababbbabbaba#ababbabbbaba"
//  0012001201210123451200123
// "ababbabbb ababbbabbaba"
//           "ababbbabbaba"

    
    