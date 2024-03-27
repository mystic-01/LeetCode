class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), ans = 1e9;
        sort(begin(nums), end(nums));
        for (int i = 0; i < n - 2; ) {
            for (int j = i + 1, k = n - 1; j < k; ) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                };
                if (sum > target) {
                    while (--k >= 0 && nums[k] == nums[k + 1]);
                } else {
                    while (++j < n && nums[j - 1] == nums[j]);
                };               
            };
            while (++i < n && nums[i - 1] == nums[i]);
        };
        return ans;
    };
};