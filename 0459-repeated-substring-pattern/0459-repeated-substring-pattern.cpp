class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (auto len = n - 1; len >= 1; len--) {
            if (n % len == 0) {
                string sub = s.substr(0, len);
                bool isRepeating = 1;
                
                for (auto i = len; i < n; i += len) {
                    if (s.substr(i, len) != sub) {
                        isRepeating = 0;
                        break;
                    };                     
                };
                if (isRepeating) return true;
            };
        };
        
        return false;
    };
};