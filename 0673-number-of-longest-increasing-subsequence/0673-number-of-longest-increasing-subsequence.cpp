struct lenAndCount {
    int len, count;
    lenAndCount(int _len, int _count) {
        len = _len, count = _count;
    };
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), count = n, maxLen = 1;
        // lenAndCount dp[n];
        vector<lenAndCount> dp(n, lenAndCount(1, 1));
        // for (int i = 0; i < n; i++) dp[i] = lenAndCount(1, 1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    int newLen = dp[j].len + 1; 
                    
                    if (newLen > dp[i].len) dp[i].count = dp[j].count, dp[i].len = newLen;
                    else if (newLen == dp[i].len) dp[i].count += dp[j].count;                    
    
                    if (newLen > maxLen) count = dp[j].count, maxLen = newLen;
                    else if (newLen == maxLen) count += dp[j].count;
                };
            };    
        };
        
        return count;
    };   
};