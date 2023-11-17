class Solution {
public:
    int minimumSum(int num) {
        multiset<int> digits;
        while (num) {
            digits.insert(num % 10);
            num /= 10;
        };
        int new1 = 0, new2 = 0;
        for (auto &x : digits) {
            if (new1 < new2) new1 = new1 * 10 + x;
            else new2 = new2 * 10 + x;
        };
        return new1 + new2; 
    };
};