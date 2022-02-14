class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int, int> m{{0, 1}};
        
        for (auto i : nums) {
            sum += i;
            count += m[sum - k];
            m[sum]++;
        };
        return count;
    };
};