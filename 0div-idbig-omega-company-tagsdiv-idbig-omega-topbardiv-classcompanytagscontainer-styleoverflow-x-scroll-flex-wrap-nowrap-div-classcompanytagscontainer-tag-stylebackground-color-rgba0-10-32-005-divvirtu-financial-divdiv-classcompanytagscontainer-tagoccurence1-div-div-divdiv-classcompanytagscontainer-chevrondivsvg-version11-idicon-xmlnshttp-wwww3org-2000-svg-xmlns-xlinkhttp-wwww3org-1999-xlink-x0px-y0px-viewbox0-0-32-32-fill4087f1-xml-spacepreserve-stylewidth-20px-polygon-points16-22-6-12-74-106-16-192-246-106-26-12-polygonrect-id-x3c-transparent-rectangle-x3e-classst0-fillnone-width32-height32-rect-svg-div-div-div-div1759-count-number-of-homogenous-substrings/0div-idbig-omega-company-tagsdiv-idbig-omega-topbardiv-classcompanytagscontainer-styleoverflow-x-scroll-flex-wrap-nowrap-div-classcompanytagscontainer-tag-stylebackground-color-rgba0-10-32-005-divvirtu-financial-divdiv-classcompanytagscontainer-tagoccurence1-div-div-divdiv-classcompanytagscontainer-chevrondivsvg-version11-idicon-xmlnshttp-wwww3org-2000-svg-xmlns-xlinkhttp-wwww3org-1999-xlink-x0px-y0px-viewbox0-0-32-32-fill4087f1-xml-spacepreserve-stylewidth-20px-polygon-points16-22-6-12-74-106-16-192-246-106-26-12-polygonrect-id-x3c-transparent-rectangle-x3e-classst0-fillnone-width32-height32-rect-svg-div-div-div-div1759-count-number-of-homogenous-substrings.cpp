class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size(), mod = 1e9 + 7, homoSubstrings = 0, count = 0;
        char lastChar = ' ';

        for (int i = 0; i < n; ++i) {
            if (lastChar == ' ') {
                ++count, lastChar = s[i];      
            } else if (lastChar == s[i]) {
                ++count;
            } else {
                count = 1, lastChar = s[i];      
            };
            homoSubstrings = (homoSubstrings + count) % mod;                
        };
        return homoSubstrings;
    };
};