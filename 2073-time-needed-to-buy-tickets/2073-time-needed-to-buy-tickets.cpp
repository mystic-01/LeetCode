class Solution {
public:
    int timeRequiredToBuy(vector<int>& nums, int k) {
        int n = nums.size(), time = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= k) {
                time += min(nums[i], nums[k]);                        
            } else {
                time += min(nums[i], nums[k] - 1);                                        
            };
        };
        return time;
    };
};