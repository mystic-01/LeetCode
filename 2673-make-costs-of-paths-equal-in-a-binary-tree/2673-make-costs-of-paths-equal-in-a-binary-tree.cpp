class Solution {
public:
    int minIncrements(int n, vector<int>& nums) {
        int increments = 0;
        for (auto i = n - 1; i >= 0; --i) {
            int leftIdx = 2 * i + 1, rightIdx = 2 * i + 2;
            if (leftIdx < n && rightIdx < n) {
                nums[i] += max(nums[leftIdx], nums[rightIdx]);
                increments += abs(nums[leftIdx] - nums[rightIdx]);                    
            };
        };
        return increments;
    };
};