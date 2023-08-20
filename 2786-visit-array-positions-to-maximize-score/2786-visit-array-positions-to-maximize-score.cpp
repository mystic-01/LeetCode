class Solution {
public:
    long long recurse(int idx, bool parity, int &n, int &x, vector<int> &nums, long long (*dp)[2]) {
        if (idx == n) return 0;
        
        if (dp[idx][parity] != -1) return dp[idx][parity];
        
        long long take = 0, notTake = 0;
        if (parity == nums[idx] % 2) take = nums[idx] + recurse(idx + 1, parity, n, x, nums, dp);
        else {
            take = nums[idx] - x + recurse(idx + 1, !parity, n, x, nums, dp);
            notTake = recurse(idx + 1, parity, n, x, nums, dp);
        };
        
        return dp[idx][parity] = max(take, notTake);
    };
    
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        bool parity = nums[0] % 2;
        long long ans = nums[0], dp[n][2];
        
        for (int i = 0; i < n; i++) dp[i][0] = dp[i][1] = -1; 
        
        ans += recurse(1, parity, n, x, nums, dp);
        
        return ans;
    };
};