class Solution {
public:
    bool pattern (string s, int i, int n) {
        bool flag = 1;
        string test = s.substr(0, i);
        for (auto j = i; j <= n - i; j += i) {
           if (test != s.substr(j, i)) {
               flag = 0;
               break;
           };
        }; 
        return flag;
    };
    
    bool repeatedSubstringPattern(string s) {
        int n = s.length(), size = sqrt(n);
        for (auto i = 2; i <= size; i++) if (n % i == 0 && (pattern(s, i, n) || pattern(s, n / i, n))) return n - 1;
        if (pattern(s, 1 , n)) return n - 1;        
        return 0;
    };
};