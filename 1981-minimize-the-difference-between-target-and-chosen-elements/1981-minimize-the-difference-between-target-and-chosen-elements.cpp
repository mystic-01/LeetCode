class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& nums, int target) {
        int row = nums.size(), col = nums[0].size();
        vector<int> dp(4901, -1), prev(4901, -1);

        for (int sum = 4900; sum >= 0; --sum) {
            prev[sum] = abs(target - sum);
        };
        
        for (int i = row - 1; i >= 0; --i) {
            for (int sum = 4830; sum >= 0; --sum) {
                int closest = 1e8;
                for (int k = 0; k < col; ++k) {
                    closest = min(closest, prev[sum + nums[i][k]]);
                };
                dp[sum] = closest;                                                
            };    
            prev = dp;
        };
        return prev[0];
    };
};