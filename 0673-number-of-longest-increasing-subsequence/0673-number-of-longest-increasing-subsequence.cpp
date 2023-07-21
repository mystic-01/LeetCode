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
        vector<lenAndCount> dp(n, lenAndCount(1, 1));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    int newLen = dp[j].len + 1; 
                    
                    if (newLen > dp[i].len) dp[i].len = newLen, dp[i].count = dp[j].count;
                    else if (newLen == dp[i].len) dp[i].count += dp[j].count;                    
    
                    if (newLen > maxLen) maxLen = newLen, count = dp[j].count;
                    else if (newLen == maxLen) count += dp[j].count;
                };
            };    
        };
        
        return count;
    };   
};