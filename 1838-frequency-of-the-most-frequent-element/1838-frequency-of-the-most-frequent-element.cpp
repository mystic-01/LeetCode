class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = nums.size(), maxFreq = 1, freq = 1;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] == nums[i + 1]) {
                ++freq;
                maxFreq = max(maxFreq, freq);                
            } else {
                int curr = nums[i + 1], kDupe = k;
                for (int j = i; j >= 0 && kDupe > 0; --j) {
                    kDupe -= (curr - nums[j]);
                    if (kDupe >= 0) {
                        ++freq;
                    };
                };
                maxFreq = max(maxFreq, freq);
                freq = 1;
            };                        
        };
        return maxFreq;
    };
};