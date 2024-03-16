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
        int n = nums.size();
        vector<vector<vector<int>>> dp(102, vector<vector<int>>(102, vector<int>(102, 0)));
        
        for (int idx = n; idx >= 0; --idx) {
            for (int target = 0; target <= k; ++target) {
                for (int count = n; count >= 0; --count) {
                    if (target == 0) {
                        dp[idx][target][count] = powerOfTwo[n - count];  
                    } else {
                        int take = 0, notTake = 0;
                        if (idx < n && target - nums[idx] >= 0) {
                            take = dp[idx + 1][target - nums[idx]][count + 1];
                        };
                        notTake = dp[idx + 1][target][count];
                        dp[idx][target][count] = (take + notTake) % mod;                    
                    };
                };            
            };        
        };
        
        return dp[0][k][0];
    };
};


/*

1 2 
3
3

3C0 -> 1
3C1 -> 3
3C2 -> 3
3C3 -> 1

E2 (1 + 1 + 2)
count[ans[i].size() to end]++

4C0 -> 1
4C1 -> 4
4C2 -> 6 - count[2]
4C3 -> 4 - count[3] - count[2] - count[1]


*/


/*

1 2 
3
3

3C0 -> 1
3C1 -> 3
3C2 -> 3
3C3 -> 1

E2 (1 + 1 + 2)
count[ans[i].size() to end]++

4C0 -> 1
4C1 -> 4
4C2 -> 6 - count[2]
4C3 -> 4 - count[3] - count[2] - count[1]


*/