// First DP Question where I wrote the code, ran it, submitted it, Accepted in a go!!!

class Solution {
public:
    int recursePlayerOneScore(int left, int right, vector<int>& nums, int (*dp)[20]) {
        if (left > right) return 0;
        
        if (dp[left][right] != -1) return dp[left][right];
        
        int oneTakeLeftSecondTakeLeft = nums[left] + recursePlayerOneScore(left + 2, right, nums, dp); // 1 + (233, 7)
        int oneTakeLeftSecondTakeRight = nums[left] + recursePlayerOneScore(left + 1, right - 1, nums, dp); // 1 + (5, 233)
        int oneTakeRightSecondTakeLeft = nums[right] + recursePlayerOneScore(left + 1, right - 1, nums, dp); // 7 + (5, 233)
        int oneTakeRightSecondTakeRight = nums[right] + recursePlayerOneScore(left, right - 2, nums, dp); // 7 + (1, 5) 
        
        return dp[left][right] = max(min(oneTakeLeftSecondTakeLeft, oneTakeLeftSecondTakeRight), min(oneTakeRightSecondTakeLeft, oneTakeRightSecondTakeRight));
    };
    
    bool PredictTheWinner(vector<int>& nums) {
        int dp[20][20];
        
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                dp[i][j] = -1;
            };        
        };        
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int firstScore = recursePlayerOneScore(0, nums.size() - 1, nums, dp);
        
        return firstScore >= sum - firstScore;
    };
};




/*

Tabulation ???


class Solution {
public:
    int recursePlayerOneScore(int left, int right, vector<int>& nums, int (*dp)[20]) {
        if (left > right) return 0;
        if (dp[left][right] != -1) return dp[left][right];
        
        int oneTakeLeftSecondTakeLeft = nums[left] + recursePlayerOneScore(left + 2, right, nums, dp); // 1 + (233, 7)
        int oneTakeLeftSecondTakeRight = nums[left] + recursePlayerOneScore(left + 1, right - 1, nums, dp); // 1 + (5, 233)
        int oneTakeRightSecondTakeLeft = nums[right] + recursePlayerOneScore(left + 1, right - 1, nums, dp); // 7 + (5, 233)
        int oneTakeRightSecondTakeRight = nums[right] + recursePlayerOneScore(left, right - 2, nums, dp); // 7 + (1, 5) 
        
        return dp[left][right] = max(min(oneTakeLeftSecondTakeLeft, oneTakeLeftSecondTakeRight), min(oneTakeRightSecondTakeLeft, oneTakeRightSecondTakeRight));
    };
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size(), dp[n][n];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
            };        
        };        
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // int firstScore = recursePlayerOneScore(0, n - 1, nums, dp);
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (i < j) {
                    dp[i][j] = 0;
                    continue;
                };
                int oneTakeLeftSecondTakeLeft = nums[i] + ((i + 2 < n && i < j) ? dp[i + 2][j] : 0);
                int oneTakeLeftSecondTakeRight = nums[i] + ((i + 1 < n && j - 1 >= 0 && i < j) ? dp[i + 1][j - 1] : 0);
                int oneTakeRightSecondTakeLeft = nums[j] + ((i + 1 < n && j - 1 >= 0 && i < j) ? dp[i + 1][j - 1] : 0);
                int oneTakeRightSecondTakeRight = nums[j] + ((j - 2 >= 0 && i < j) ? dp[i][j - 2] : 0);
                
                dp[i][j] = max(min(oneTakeLeftSecondTakeLeft, oneTakeLeftSecondTakeRight), min(oneTakeRightSecondTakeLeft, oneTakeRightSecondTakeRight));
                cout << dp[i][j] << " ";
            };
        };
        int firstScore = dp[0][n - 1];
                cout << firstScore << "\n";
        
        return firstScore >= sum - firstScore;
    };
};

*/