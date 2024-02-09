class Solution {
public:
    int numTrees(int n) {
        int dp[20] = {0};
        dp[0] = 1;
        
        for (int idx = 0; idx <= n; ++idx) {
            for (int i = 0; i < idx; ++i) {
                dp[idx] += (dp[i] * dp[idx - i - 1]);
            };
        };
        return dp[n];
    };    
};

// numTree(0) = 1
// numTree(1) = 1 + 1 + 0 = 1
// numTree(2) = 1 + 1 + 0 = 2
// numTree(3) = 2 + 2 + 1 = 5
