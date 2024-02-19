static const int outOfBounds = INT_MAX;

class Solution {
public:
    int recurse(int i, int j, int &row, vector<vector<int>> &triangle, vector<vector<int>> &dp) {
        if (i == row - 1) {
            return triangle[i][j];    
        } else if (j >= triangle[i].size()) {
            return outOfBounds;
        };        
        if (dp[i][j] != -1) {
            return dp[i][j];
        };
        int left = recurse(i + 1, j, row, triangle, dp);
        int right = recurse(i + 1, j + 1, row, triangle, dp);
        return dp[i][j] = triangle[i][j] + min(left, right);
    };
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<vector<int>> dp(row, vector<int>(row, -1));
        return recurse(0, 0, row, triangle, dp);
    };
};