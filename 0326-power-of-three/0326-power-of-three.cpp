class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && (long)pow(3, 31) % (long)n == 0;        
    };
};