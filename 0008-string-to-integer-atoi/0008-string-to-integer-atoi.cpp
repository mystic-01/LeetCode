class Solution {
public:
    int myAtoi(string s) {
        long num = 0, sign = 0, seenDigit = 0;
        for (char &ch : s) {
            if (ch == '+' || ch == '-') {
                if (sign || seenDigit) {
                    break;    
                };
                sign = ch == '+' ? 1 : -1;
            } else if (isdigit(ch)) {
                int digit = ch - '0';
                num *= 10;
                num += digit;
                seenDigit = 1;
                if (num > INT_MAX) {
                    num = sign >= 0 ? INT_MAX : INT_MAX + 1LL;     
                };
            } else if (ch != ' ' || sign || seenDigit) {
                break;    
            };
        };
        return num * (sign == 0 ? 1 : sign);
    };
};