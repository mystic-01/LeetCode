class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size(), maxFromLeft = -1, minTillHere[n];
        for (int i = n - 1; i >= 0; --i) {
            minTillHere[i] = min(nums[i], i + 1 < n ? minTillHere[i + 1] : INT_MAX);
        };
        for (int i = 0; i < n - 1; ++i) {
            maxFromLeft = max(maxFromLeft, nums[i]);
            if (maxFromLeft <= minTillHere[i + 1]) {
                return i + 1;
            };
        };
        return -1;
    };
};