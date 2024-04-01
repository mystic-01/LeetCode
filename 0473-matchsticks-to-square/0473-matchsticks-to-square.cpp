class Solution {
public:
    bool recurse(int idx, int target, int k, vector<int> &nums, int &sumBy4) {
        if (k == 0) {
            return true;               
        };
        if (target == 0) {
            return recurse(0, sumBy4, k - 1, nums, sumBy4);
        };
        if (idx == nums.size()) {
            return false;
        };     
        if (target - nums[idx] >= 0) {
            target -= nums[idx];
            int temp = nums[idx];
            nums[idx] = INT_MAX;
            if (recurse(idx + 1, target, k, nums, sumBy4)) {
                return true;
            };
            nums[idx] = temp;
            target += nums[idx];
        };
        return recurse(idx + 1, target, k, nums, sumBy4);
    };

    
    bool makesquare(vector<int>& nums) {
        int n = nums.size(), totSum = accumulate(begin(nums), end(nums), 0), target = totSum / 4;
        if (totSum % 4) {
            return false;            
        };
        // sort(begin(nums), end(nums));
        return recurse(0, target, 4, nums, target);
    };
};