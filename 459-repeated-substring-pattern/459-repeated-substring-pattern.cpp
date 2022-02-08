class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length(), size = sqrt(n), flag = 1;
        string test = "";
        for (auto i = 2; i <= size; i++) {
            if (n % i == 0) {
                flag = 1;
                test = s.substr(0, i);
                for (auto j = i; j <= n - i; j += i)
                   if (test != s.substr(j, i)) { flag = 0; break; };
                if (flag) return n - 1;
                
                int nByI = n / i;
                flag = 1;
                test = s.substr(0, nByI);
                for (auto j = nByI; j <= n - nByI; j += nByI)
                   if (test != s.substr(j, nByI)) { flag = 0; break; };
                if (flag) return n - 1;
            };
        };
        flag = 1;
        test = s.substr(0, 1);
        for (auto j = 1; j <= n - 1; j++) 
            if (test != s.substr(j, 1)) { flag = 0; break; };
        if (flag) return n - 1;
        return 0;
    };
};