static const int outOfBound = 1e5;
class Solution {
public:
    int recurse(int idx, int target, int &sqSize, int *squares, vector<vector<int>> &dp) {
        if (idx == sqSize) {
            return target == 0 ? 0 : outOfBound;    
        };    
        if (dp[idx][target] != -1) {
            return dp[idx][target];  
        };
        int take = (target >= squares[idx] ? 1 + recurse(idx, target - squares[idx], sqSize, squares, dp) : outOfBound);
        int notTake = recurse(idx + 1, target, sqSize, squares, dp);
        
        return dp[idx][target] = min(take, notTake);
    };
    
    int numSquares(int n) {
        int sqSize = sqrt(n) + 1, squares[sqSize];        
        for (int i = 1; i < sqSize; ++i) {
            squares[i] = i * i;                
        };
        vector<vector<int>> dp(101, vector<int>(n + 1, -1));
        return recurse(1, n, sqSize, squares, dp);         
    };
};