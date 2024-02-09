class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (!nums.size()) {
            return {};
        };
        sort(begin(nums), end(nums));
        int n = nums.size(), maxVal = 0, maxIdx = 0;

        pair<int, int> dp[n];
        vector<int> finalSubset;
        
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = {0, -1};
            for (int j = i; j < n; ++j) {
                if (nums[j] % nums[i] == 0 && 1 + dp[j].first > dp[i].first) {
                    dp[i] = {1 + dp[j].first, j};
                };
            };
            if (dp[i].first > maxVal) {
                 maxVal = dp[i].first, maxIdx = i;    
            };
        };
        for (int i = maxIdx; i < n && maxVal; --maxVal) {
            finalSubset.push_back(nums[i]), i = dp[i].second; 
        };
        
        return finalSubset;
    };
};