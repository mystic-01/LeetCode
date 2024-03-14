class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), sum = 0, count = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (m.find(sum - goal) != m.end()) {
                count += m[sum - goal];     
            };
            ++m[sum];
        };
        return count;
    };
};