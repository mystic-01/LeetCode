class Solution {
public:
    bool recurse(int idx, int k, int target, vector<int> &nums, int &originalTarget) {
        if (k == 0) {
            return true;
        };
        if (target == 0) {
            return recurse(0, k - 1, originalTarget, nums, originalTarget);            
        };
        if (idx == nums.size()) {
            return false;
        };
        if (target - nums[idx] >= 0) {
            int temp = nums[idx];
            target -= temp;
            nums[idx] = INT_MAX;
            if (recurse(idx + 1, k, target, nums, originalTarget)) {
                return true;
            };
            nums[idx] = temp;
            target += temp;
        };
        return recurse(idx + 1, k, target, nums, originalTarget);
    };
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(begin(nums), end(nums), 0), target = sum / k;
        if (sum % k) {
            return false;
        };
        sort(begin(nums), end(nums), greater<int>());
        return recurse(0, k, target, nums, target);
    };
};