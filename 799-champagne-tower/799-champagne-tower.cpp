class Solution {
public:
    double champagneTower(int poured, int row, int glass) {
        
        vector<double> dp(row + 1, 0.0);
        dp[0] = double(poured);
        
        for (auto i = 1; i <= row; i++) {
            vector<double> curr(row + 1, 0.0);
            for (auto j = 0; j <= glass; j++) {
                double prevRowPrevCol = 0.0, prevRowCurrCol = 0.0;  
                if (j - 1 >= 0) 
                    prevRowPrevCol = (dp[j - 1] - 1.0) / 2.0; 

                if (j <= i - 1) 
                    prevRowCurrCol = (dp[j] - 1.0) / 2.0; 

                curr[j] = max(prevRowPrevCol, 0.0) + max(prevRowCurrCol, 0.0);
            };
            dp = curr;
        };
        return min(1.0, dp[glass]);
    };
};
