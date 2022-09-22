class Solution {
public:
    int reverse(int x) {
        if (x <= INT_MIN) return 0;
        
        bool isNegative = x < 0;
        int num =  isNegative ? -1 * x : x, copy = num, digits = 0;
        long ans = 0;
        while (copy) digits++, copy /= 10;

        copy = num;
        while (digits--) {
            ans += (pow(10, digits) * (copy % 10)), copy /= 10;
        };
        ans = isNegative ? -1 * ans : ans;
        
        return ans > INT_MIN && ans <= INT_MAX - 1 ? ans : 0;
    };
};