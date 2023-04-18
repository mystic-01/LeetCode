class Solution {
public:
    int reverse(int x) {
        
        bool isNegative = x < 0;
        long num = x, ans = 0;        
        
        num = isNegative ? -1L * x : x;
        
        while (num) ans = (ans * 10) + (num % 10), num /= 10;

        ans = isNegative ? -1L * ans : ans;
        
        return ans > INT_MIN && ans <= INT_MAX - 1 ? ans : 0;
    };
};