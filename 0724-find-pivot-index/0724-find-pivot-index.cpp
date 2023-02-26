class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), leftSum = 0;
        vector<int> rightSum(n, 0);
        for (auto i = n - 2; i >= 0; i--) rightSum[i] = rightSum[i + 1] + nums[i + 1];
        for (auto i = 0; i < n; i++) if (leftSum == rightSum[i]) return i; else leftSum += nums[i];
        
        return -1;
    };
};