class Solution {
public:
    
    int mySqrt(int x) {
        int xCopy = x, i = 1, count = 0;
        if (x == 0) return 0;
        if (x == 2) return 1;

        while (i <= x/i) {
            // cout << i * i << endl;
            i++;
        };
        return --i;
    };
};