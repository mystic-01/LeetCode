class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size(), maxFreq = 0;
        
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                bool foundDifferent = 0;
                for (int j = i + 1; j < n; j++) {
                    if (s[i] != s[j]) {
                        swap(s[i], s[j]);
                        foundDifferent = 1;
                        break;
                    };                        
                };
                // if (!foundDifferent) break;
            };
        };
        
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == s[i + 1]) {
                bool foundDifferent = 0;
                for (int j = i - 1; j >= 0; j--) {
                    if (s[i] != s[j]) {
                        swap(s[i], s[j]);
                        foundDifferent = 1;
                        break;
                    };                        
                };
                if (!foundDifferent) return "";
            };
        };
        return s;
    };
};


/*

3 2 2
abacabc

3 a
2 b
2 c

a b c 

*/