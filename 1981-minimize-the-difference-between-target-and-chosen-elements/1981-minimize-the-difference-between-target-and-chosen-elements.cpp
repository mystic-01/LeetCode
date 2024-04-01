class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& nums, int target) {
        int row = nums.size(), col = nums[0].size(), maxSum = 0, maxVal = 0;
        
        for (auto &vec : nums) {
            sort(begin(vec), end(vec), greater<int>());            
        };
        for (int i = row - 1; i >= 0; --i) {
            maxSum += nums[i][0], maxVal = max(maxVal, nums[i][0]);
        };
        
        vector<int> dp(maxSum + maxVal + 1, 0), prev(maxSum + maxVal + 1, 0);

        for (int sum = maxSum + maxVal; sum >= 0; --sum) {
            prev[sum] = abs(target - sum);
        };
        
        for (int i = row - 1; i >= 0; --i) {
            for (int sum = maxSum; sum >= 0; --sum) {
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