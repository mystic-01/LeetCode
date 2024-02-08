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
        int sq = idx * idx;
        int take = (target >= sq ? 1 + recurse(idx, target - sq, sqSize, dp) : outOfBound);
        int notTake = recurse(idx + 1, target, sqSize, dp);
        
        return dp[idx][target] = min(take, notTake);
    };
    
    int numSquares(int n) {
        int sqSize = sqrt(n) + 1;
        vector<vector<int>> dp(101, vector<int>(n + 1, -1));
        return recurse(1, n, sqSize, dp);         
    };
};