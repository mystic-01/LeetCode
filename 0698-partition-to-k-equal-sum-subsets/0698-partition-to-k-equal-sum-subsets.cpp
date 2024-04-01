class Solution {
public:
    bool recurse(int idx, int k, int &t, vector<int> &nums, int &target) {
        if (k == 0) {
            return true;
        };
        if (t == 0) {
            t = target;
            if (recurse(0, k - 1, t, nums, target)) {
                return true;
            };            
            t = 0;
            return false;
        };
        if (idx == nums.size()) {
            return false;
        };
        if (t - nums[idx] >= 0) {
            int temp = nums[idx];
            t -= temp;
            nums[idx] = INT_MAX;
            if (recurse(idx + 1, k, t, nums, target)) {
                return true;
            };
            nums[idx] = temp;
            t += temp;
        };
        return recurse(idx + 1, k, t, nums, target);
    };
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(begin(nums), end(nums), 0), target = sum / k, t = target;
        if (sum % k) {
            return false;
        };
        sort(begin(nums), end(nums), greater<int>());
        return recurse(0, k, t, nums, target);
    };
};