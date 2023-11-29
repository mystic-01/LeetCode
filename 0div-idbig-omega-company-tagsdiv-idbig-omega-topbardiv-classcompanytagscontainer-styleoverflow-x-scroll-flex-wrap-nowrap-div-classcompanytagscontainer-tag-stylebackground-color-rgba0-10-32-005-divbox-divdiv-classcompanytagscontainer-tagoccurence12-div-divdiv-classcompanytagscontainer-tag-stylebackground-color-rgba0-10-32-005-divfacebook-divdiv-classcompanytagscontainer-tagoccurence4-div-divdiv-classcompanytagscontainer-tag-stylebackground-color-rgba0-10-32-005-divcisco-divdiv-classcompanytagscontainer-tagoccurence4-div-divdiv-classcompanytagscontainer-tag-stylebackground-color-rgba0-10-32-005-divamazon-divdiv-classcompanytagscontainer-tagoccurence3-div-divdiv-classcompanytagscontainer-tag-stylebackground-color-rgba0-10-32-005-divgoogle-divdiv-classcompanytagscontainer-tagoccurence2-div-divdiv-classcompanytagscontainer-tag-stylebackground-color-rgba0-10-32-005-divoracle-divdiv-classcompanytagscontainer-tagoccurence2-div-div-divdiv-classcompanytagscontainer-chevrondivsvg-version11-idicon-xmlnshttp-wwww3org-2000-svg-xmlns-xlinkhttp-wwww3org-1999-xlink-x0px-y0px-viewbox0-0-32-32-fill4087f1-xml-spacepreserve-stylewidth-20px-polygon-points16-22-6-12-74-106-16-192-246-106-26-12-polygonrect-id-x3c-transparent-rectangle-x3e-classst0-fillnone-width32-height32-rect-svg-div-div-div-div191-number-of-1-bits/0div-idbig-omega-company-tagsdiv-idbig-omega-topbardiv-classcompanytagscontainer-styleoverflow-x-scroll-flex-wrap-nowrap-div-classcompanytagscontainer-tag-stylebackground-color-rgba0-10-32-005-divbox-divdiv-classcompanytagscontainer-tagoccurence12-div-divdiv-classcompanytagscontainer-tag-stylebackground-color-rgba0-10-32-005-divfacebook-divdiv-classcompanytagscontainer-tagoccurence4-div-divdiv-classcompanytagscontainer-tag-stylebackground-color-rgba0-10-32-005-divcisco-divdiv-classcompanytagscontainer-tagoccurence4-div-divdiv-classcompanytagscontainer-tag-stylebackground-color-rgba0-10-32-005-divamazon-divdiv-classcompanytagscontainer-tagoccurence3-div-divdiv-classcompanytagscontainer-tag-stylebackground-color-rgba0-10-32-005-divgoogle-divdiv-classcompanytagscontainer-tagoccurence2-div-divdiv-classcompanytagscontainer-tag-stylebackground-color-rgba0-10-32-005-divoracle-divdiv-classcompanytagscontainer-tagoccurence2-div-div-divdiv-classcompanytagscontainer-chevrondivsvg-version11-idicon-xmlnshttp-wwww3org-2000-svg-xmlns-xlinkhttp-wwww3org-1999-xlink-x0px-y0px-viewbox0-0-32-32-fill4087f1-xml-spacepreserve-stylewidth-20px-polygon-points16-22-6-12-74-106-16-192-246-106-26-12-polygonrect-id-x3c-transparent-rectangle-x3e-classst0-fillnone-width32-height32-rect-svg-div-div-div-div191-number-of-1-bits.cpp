class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bits = 0;
        while (n) {
            if (n % 2) ++bits;
            n /= 2;
        };      
        return bits;
    };
};