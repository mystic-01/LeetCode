class Solution {
public:
    int divide(int divid, int divis) {
        if (divid == INT_MIN && divis == -1) {
            return INT_MAX;    
        };
        
        long dividend = abs(long(divid)), divisor = abs(long(divis)), quotient = 0;
        while (dividend >= divisor) {
            long temp = divisor, res = 1;
            while (dividend - temp >= temp) {
                temp += temp;
                res += res;
            };
            dividend -= temp;
            quotient += res;
        };
        return quotient * (divid >= 0 == divis >= 0 ? 1 : -1);
    };
};