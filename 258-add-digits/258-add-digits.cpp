class Solution {
public:
    int addDigits(int num) {
        int ans = 0;
        while (1) {
            ans = 0;
            while (num) {
                ans += num % 10;
                num /= 10;
            };
            if (ans < 10) return ans;
            num = ans;
        };
        return ans;
    };
};