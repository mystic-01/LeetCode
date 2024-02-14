class Solution {
public:
    // KMP / Z-function
    void fillLps(vector<int> &pattern, int *lps) {
        int i = 0, prev = 0, m = pattern.size();
        lps[i++] = 0;
        while (i < m) {
            if (pattern[i] == pattern[prev]) {
                lps[i] = prev + 1, i++, prev++;
            } else {
                if (prev == 0) {
                    lps[i] = 0, i++;    
                } else {
                    prev = lps[prev - 1];    
                };    
            };    
        };        
    };
    
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size(), countMatched = 0, lps[m + 1];
        fillLps(pattern, lps);
        vector<int> curr(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] - nums[i + 1] < 0) {
                curr[i] = 1;
            } else if (nums[i] - nums[i + 1] > 0) {
                curr[i] = -1;
            } else {
                curr[i] = 0;
            };
        };
        
        int i = 0, j = 0;
        while (i < n - 1 && j < m) {
            if (curr[i] == pattern[j]) {
                ++i, ++j;                                                
            } else {
                if (j == 0) {
                    ++i;
                } else {
                    j = lps[j - 1];
                };
            };
            if (j == m) {
                ++countMatched, j = lps[j - 1];
            };
        };
        return countMatched;
    };
};















