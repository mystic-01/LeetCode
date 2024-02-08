class Solution {
private:
    int nLimit = 1e4, sqSize = sqrt(nLimit) + 1, squares[101], outOfBound = 1e5;
public:
    Solution() {
        for (int i = 1; i < sqSize; ++i) {
            squares[i] = i * i;                
        };
    };
    
    int recurse(int idx, int target, vector<vector<int>> &dp) {
        if (idx == sqSize) {
            return target == 0 ? 0 : outOfBound;    
        };    
        if (dp[idx][target] != -1) {
            return dp[idx][target];  
        };
        int take = (target >= squares[idx] ? 1 + recurse(idx, target - squares[idx], dp) : outOfBound);
        int notTake = recurse(idx + 1, target, dp);
        
        return dp[idx][target] = min(take, notTake);
    };
    
    int numSquares(int n) {
        vector<vector<int>> dp(101, vector<int>(n + 1, -1));
        return recurse(1, n, dp);         
    };
};