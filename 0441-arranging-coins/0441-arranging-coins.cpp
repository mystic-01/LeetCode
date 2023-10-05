class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0, stepsNeeded = 0;    
        while (n > 0) {
            n -= ++stepsNeeded;
            if (n >= 0) ++ans;
        };
        return ans;
    };
};