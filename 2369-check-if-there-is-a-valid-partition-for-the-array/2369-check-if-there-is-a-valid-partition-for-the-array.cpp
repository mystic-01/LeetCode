class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size(), dp[n + 1];        
        for (int i = 0; i < n + 1; i++) dp[i] = -1;
        dp[n] = 1;
        
        for (int idx = n - 1; idx >= 0; idx--) {
            bool ans = 0;
            int startVal = nums[idx], twoSame = 1, threeSame = 1, threeIncrease = 1;
        
            for (int i = idx + 1; i < nums.size() && i < idx + 3; i++) {
                if (nums[i] == startVal) twoSame++, threeSame++;
                if (nums[i] == nums[i - 1] + 1) threeIncrease++;
            };
        
            if (twoSame >= 2) ans = ans || dp[idx + 2];
            if (threeSame == 3) ans = ans || dp[idx + 3];
            if (threeIncrease == 3) ans = ans || dp[idx + 3];
            
            dp[idx] = ans;                                    
        };
        
        return dp[0];
    };
};