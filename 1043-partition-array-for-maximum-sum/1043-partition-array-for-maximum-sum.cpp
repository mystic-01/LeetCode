class Solution {
public:
    int recurse(int idx, vector<int>& arr, int &k, int *dp) {
        if (idx >= arr.size()) return 0;
        if (dp[idx] != -1) return dp[idx];
        
        int sum = 0, ansWithCurrWindow = 0, maxWithCurrWindow = 0;
        for (int i = 0; i < k && idx + i < arr.size(); ++i) {
            maxWithCurrWindow = max(arr[idx + i], maxWithCurrWindow);  
            
            ansWithCurrWindow = maxWithCurrWindow * (i + 1) + recurse(idx + i + 1, arr, k, dp);
            
            sum = max(sum, ansWithCurrWindow);
        };
        return dp[idx] = sum;
    };
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size(), dp[n + 1];
        fill(dp, dp + n + 1, -1);
        return recurse(0, arr, k, dp);
    };
};