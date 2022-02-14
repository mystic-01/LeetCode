class Solution {
public:
    int getLucky(string s, int k) {
        int n = s.length(), x = 0, sum = 0;
        for (auto i = 0; i < n; i++) {
            x = (s[i] - 'a' + 1);
            while (x) {
                sum += x % 10;
                x /= 10;
            };
        };
        while (--k) {
            x = 0;
            while (sum) {
                x += sum % 10;
                sum /= 10;
            };   
            sum = x;
        };
        return sum;
    };
};