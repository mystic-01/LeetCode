class Solution {
public:
    int climbStairs(int n) {
        int dp = 0, prev1 = 1, prev2 = 0;
        
        for (int pos = n - 1; pos >= 0; pos--) {
            dp = prev1 + prev2;
            prev2 = prev1;
            prev1 = dp;
        };
        
        return dp;
    };
};