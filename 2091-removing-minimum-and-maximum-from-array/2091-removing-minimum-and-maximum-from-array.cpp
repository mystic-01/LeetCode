class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(), maxIdx = 0, minIdx = 0, currMax = INT_MIN, currMin = INT_MAX;
        for (auto i = 0; i < n; i++) {
            if (nums[i] < currMin) currMin = nums[minIdx = i];
            if (nums[i] > currMax) currMax = nums[maxIdx = i];
        };
        
        if (minIdx > maxIdx) swap(maxIdx, minIdx);
        return min(n - maxIdx + minIdx + 1, min(maxIdx + 1, n - minIdx));
    };
};