class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size(), xorVal = 0;
        for (int i = 1; i <= size; ++i) {
            xorVal ^= i;
        };
        for (int i = 0; i < size; ++i) {
            xorVal ^= nums[i];
        };        
        return xorVal;
    };
};