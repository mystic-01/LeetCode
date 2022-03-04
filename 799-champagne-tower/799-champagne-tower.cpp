class Solution {
public:
    double champagneTower(int poured, int row, int glass) {
        
        vector<vector<double>> dp(row + 1, vector<double>(row + 1, 0.0));
        dp[0][0] = double(poured);
        
        for (auto i = 1; i <= row; i++) {
            for (auto j = 0; j <= glass; j++) {
                double prevRowPrevCol = 0.0, prevRowCurrCol = 0.0;  
                if (j - 1 >= 0) 
                    prevRowPrevCol = (dp[i - 1][j - 1] - 1.0) / 2.0; 

                if (j <= i - 1) 
                    prevRowCurrCol = (dp[i - 1][j] - 1.0) / 2.0; 

                dp[i][j] = max(prevRowPrevCol, 0.0) + max(prevRowCurrCol, 0.0);
            };
        };
        return min(1.0, dp[row][glass]);
    };
};
