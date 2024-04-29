class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size(), xorVal = nums[0], diff = 0;
        for (int i = 1; i < n; ++i) {
            xorVal ^= nums[i];
        };
        for (int i = 0; i < 32; ++i) {
            int bitA = xorVal & (1 << i);
            int bitB = k & (1 << i);
            diff += (bitA != bitB);
        };        
        return diff;
    };
};
        
        