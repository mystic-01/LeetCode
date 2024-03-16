static int mod = 1e9 + 7;
static int powerOfTwo[102] = {0};

class Solution {
public:
    Solution() {
        powerOfTwo[0] = 1;
        for (int i = 1; i <= 101; ++i) {
            long long temp = (powerOfTwo[i - 1] * 2) % mod;                        
            powerOfTwo[i] = temp;
        };    
    };
    
    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size(), dp[102][102], prev[102][102];
        for (int i = 0; i < 102; ++i) {
            for (int j = 0; j < 102; ++j) {
                prev[i][j] = dp[i][j] = 0;
            };         
        };
        
        for (int idx = n; idx >= 0; --idx) {
            for (int target = 0; target <= k; ++target) {
                for (int count = n; count >= 0; --count) {
                    if (target == 0) {
                        dp[target][count] = powerOfTwo[n - count];  
                    } else {
                        int take = 0, notTake = 0;
                        if (idx < n && target - nums[idx] >= 0) {
                            take = prev[target - nums[idx]][count + 1];
                        };
                        notTake = prev[target][count];
                        dp[target][count] = (take + notTake) % mod;                    
                    };
                };            
            };        
            for (int i = 0; i < 102; ++i) {
                for (int j = 0; j < 102; ++j) {
                    prev[i][j] = dp[i][j];
                };         
            };
        };
        
        return dp[k][0];
    };
};