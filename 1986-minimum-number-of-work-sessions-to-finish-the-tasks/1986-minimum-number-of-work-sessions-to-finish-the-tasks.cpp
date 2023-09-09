class Solution {
public:
    int recurse(int tasks, int timeLeft, int &sessionTime, int &n, vector<int>& nums, int (*dp)[16]) {
        // cout << tasks << "\n";
        if (tasks == pow(2, n) - 1) return 1;
        
        if (dp[tasks][timeLeft] != -1) return dp[tasks][timeLeft];
        
        int ans = 2147483647;
        for (int i = 0; i < nums.size(); i++) {
            if (!(1 << i & tasks)) {
                int curr = 2147483647, newTasks = ((1 << i) | tasks);
                if (timeLeft - nums[i] >= 0) curr = recurse(newTasks, timeLeft - nums[i], sessionTime, n, nums, dp);
                else curr = 1 + recurse(newTasks, sessionTime - nums[i], sessionTime, n, nums, dp);
                ans = min(ans, curr);
            };                
        };
        return dp[tasks][timeLeft] = ans;
    };
    
    int minSessions(vector<int>& nums, int sessionTime) {
        int n = nums.size(), maxTasks = pow(2, n), tasks = 0, dp[maxTasks][16];
        for (int i = 0; i < maxTasks; i++) {
            for (int j = 0; j < 16; j++) {
                dp[i][j] = -1;                
            };
        };        
        return recurse(tasks, sessionTime, sessionTime, n, nums, dp);
    };
};