class Solution {
public:
    int sum(int a, int b) {
        while (b != 0) {
            unsigned carry = a & b;
            a = a ^ b;
            b = carry << 1;
        };
        return a;
    };
};