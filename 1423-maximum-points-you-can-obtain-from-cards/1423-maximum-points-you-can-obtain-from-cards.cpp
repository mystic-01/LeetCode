class Solution {
public:
    int maxScore(vector<int>& nums, int k) {        
        int n = nums.size(), lSum = 0, rSum = 0, best = 0;

        for (int i = 0; i < k; i++) lSum += nums[i];

        best = lSum;
        for (int i = 0; i < k; i++) {
            rSum += nums[n - i - 1];
            lSum -= nums[k - i - 1];
            best = max(best, lSum + rSum);
        };
        return best;
    };
};