class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       std::ios::sync_with_stdio(false);
       std::cin.tie(nullptr);
       int n = digits.size() - 1, c = 1;
        while(c != 0 && n >= 0) {
            int next = digits[n] + 1;
            digits[n--] = next % 10;
            c = next / 10;
        };
        if (c == 1) digits.insert(digits.begin(), c);
        return digits;
    };
};