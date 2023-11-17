class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> digits;
        int ans = 0;
        double size = max(1.0, ceil(log(n)));
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        };
        reverse(begin(digits), end(digits));
        digits.resize(size);
        for (int i = 0; i < size; ++i) {
            ans += (i % 2 ? -1 * digits[i] : digits[i]);
        };
        return ans;
    };
};
