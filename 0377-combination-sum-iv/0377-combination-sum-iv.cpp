class Solution {
public:
    int recurse(int idx, int target, int &n, vector<int> &nums, int (*dp)[1001]) {
        if (target == 0) return 1;
        if (idx == n) return 0;
    
        if (dp[idx][target] != -1)  return dp[idx][target];
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (target - nums[i] >= 0) {
                ans += recurse(i, target - nums[i], n, nums, dp);    
            };
        };
        return dp[idx][target] = ans;
    };    

    
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size(), dp[n + 1][1001];
        
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < 1001; j++) {
                dp[i][j] = -1;    
            };
        };
        
        return recurse(0, target, n, nums, dp);    
    };
};