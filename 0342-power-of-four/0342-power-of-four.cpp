class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && !(n & n - 1) && (n & 0xaaaaaaaa) == 0;       
    };
};


/*
1 - 001
3 - 011
4 - 100
5 - 101
6 - 110
7 - 111
8 -1000

*/