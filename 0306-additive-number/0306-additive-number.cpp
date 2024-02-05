static const int limit = 19;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int len1 = 1; len1 <= min(limit, n); ++len1) {
            long long num1 = stoll(num.substr(0, len1));
            if (num1 > LLONG_MAX || (num[0] == '0' && num1 > 0)) {
                return false;
            };
            
            for (int len2 = 1; len2 <= min(limit, n - len1); ++len2) {
                long long num2 = stoll(num.substr(len1, len2));
                if (num2 > LLONG_MAX || (num[len1] == '0' && num2 > 0)) {
                    break;
                };
                
                int len3 = 1, start = len1 + len2;
                long long last1 = num1, last2 = num2;
                if (start == n) {
                    break;
                };   
                while (start < n && len3 <= min(limit, n - len1 - len2)) {
                    long long num3 = stoll(num.substr(start, len3));
                    // cout << last1 << " " << last2 << " " << num3 << " " << "\n";
                    if (num3 > LLONG_MAX || (num[start] == '0' && num3 > 0)) {
                        break;
                    };
                    if (last1 + last2 == num3) {
                        start += len3, len3 = 1, last1 = last2, last2 = num3;
                    } else if (num3 > last1 + last2) {
                        break;
                    } else {
                        ++len3;                        
                    };
                };
                if (start == n) {
                    return true;
                };                  
            };        
  
        };
        // cout << "\n";
        return false;
    };
};