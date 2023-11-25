class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size(), totSum = accumulate(begin(nums), end(nums), 0), lSum = 0;
        vector<int> ans(n);    
        for (int i = 0, sum = 0; i < n; ++i) {
            ans[i] = ((nums[i] * i) - lSum) + (totSum - lSum - (nums[i] * (n - i)));
            lSum += nums[i];    
        };
        return ans;
    };
};