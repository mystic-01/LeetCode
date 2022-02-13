class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), average = nums[n / 2], totalDiff = 0;
        
        for (auto i = 0; i < n; i++) totalDiff += (abs(nums[i] - average));             
        return totalDiff;
    };
};