class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long int nn = n;
        nn *= (nn < 0) ? -1 : 1;
        x = (n > 0) ? x : 1/x;
        while (nn) {
            if (nn % 2) {
                ans *= x;
                nn -= 1;
            } else {
                x *= x;
                nn /= 2;
            }
        }
        return nn < 0 ? (double) 1/ans : ans;
    }
};