class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        bool isNeg = n < 0;
        long long power = isNeg ? -1LL * n : n;
        
        while (power) {
            if (power % 2) ans *= x, power--;
            else x *= x, power /= 2;
        };
        return isNeg ? 1.0 / ans : ans;
    };
};