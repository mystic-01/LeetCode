class Solution {
public:
    bool checkRecord(string s) {
        for (int i = 0, n = s.size(), a = 0, l = 0; i < n; ++i) {
            if (s[i] == 'A') {
                ++a, l = 0;
            } else if (s[i] == 'L') {
                ++l;
            } else {
                l = 0;
            };
            if (a > 1 || l > 2) {
                return false;
            };
        };    
        return true;
    };
};