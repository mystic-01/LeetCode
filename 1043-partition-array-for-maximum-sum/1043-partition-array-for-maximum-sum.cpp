class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size(), dp[n + 1];
        fill(dp, dp + n + 1, 0);

        for (int idx = n - 1; idx >= 0; --idx) {
            int currAns = 0, currMax = 0;
            for (int i = 0; i < k && idx + i < n; ++i) {
                currMax = max(arr[idx + i], currMax);  
                currAns = currMax * (i + 1) + (idx + i + 1 >= n ? 0 : dp[idx + i + 1]);
                dp[idx] = max(dp[idx], currAns);
            };
        };
        return dp[0];
    };
};