class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length(), size = sqrt(n);
        vector<int> factors;
        for (auto i = 2; i <= size; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                factors.push_back(n / i);
            };
        };
        factors.push_back(1);

        for (auto i : factors) {
            bool flag = 1;
            string test = s.substr(0, i);
            for (auto j = i; j <= n - i; j += i) {
               if (test != s.substr(j, i)) {
                   flag = 0;
                   break;
               };
            };
            if (flag) return n - 1;
        };
        return 0;
    };
};