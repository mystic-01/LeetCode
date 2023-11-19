class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size(), ops = 0, sortedPosition = 0, size = 5 * 1e4 + 1, freq[size];
        for (int i = 0; i < size; ++i) {
            freq[i] = 0;
        };
        for (int &x : nums) {
            ++freq[x];    
        };
        for (int i = 0; i < size; ++i) {
            if (freq[i]) {
                ops += (freq[i] * sortedPosition);
                ++sortedPosition;
            };
        };
        return ops;
    };
};