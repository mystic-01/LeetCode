class Solution {
public:
    int countTrees(int n, int *dp) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (dp[n] != 0) return dp[n];
            
        int count = 0;
        for (int i = 0; i < n; ++i) {
            count += (countTrees(i, dp) * countTrees(n - i - 1, dp)); 
        };
        return dp[n] = count;
    };
    int numTrees(int n) {
        int dp[20] = {0};
        return countTrees(n, dp);
    };    
};

// numTree(0) = 1
// numTree(1) = 1 + 1 + 0 - 1 = 1
// numTree(2) = 1 + 1 + 0 - 1 = 1
// numTree(3) = 3 + 3 + 1 + 0 = 7
