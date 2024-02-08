static const int outOfBound = 1e5;
class Solution {
public:
    int recurse(int idx, int target, int &sqSize, vector<vector<int>> &dp) {
        if (idx == sqSize) {
            return target == 0 ? 0 : outOfBound;    
        };    
        if (dp[idx][target] != -1) {
            return dp[idx][target];  
        };
        int take = outOfBound, notTake = outOfBound, newTarget = target - (idx * idx);
        if (newTarget >= 0) {
            take = 1 + recurse(idx, newTarget, sqSize, dp);
        };
        notTake = recurse(idx + 1, target, sqSize, dp);
        
        return dp[idx][target] = min(take, notTake);
    };
    
    int numSquares(int n) {
        int sqSize = sqrt(n) + 1;
        vector<vector<int>> dp(101, vector<int>(n + 1, -1));
        return recurse(1, n, sqSize, dp);         
    };
};