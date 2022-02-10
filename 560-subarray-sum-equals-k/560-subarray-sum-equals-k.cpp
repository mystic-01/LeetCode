class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, count = 0;
        unordered_map<int, int> m = {{0, 1}};
        
        for (auto i = 0; i < n; i++) {
            sum += nums[i];count += m[sum - k];
            m[sum]++;
        };
        return count;
    };
};