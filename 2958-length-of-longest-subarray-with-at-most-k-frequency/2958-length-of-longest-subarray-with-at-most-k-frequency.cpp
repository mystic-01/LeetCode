class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, best = 0;
        unordered_map<int, int> m;
        for (int right = 0; right < n; ++right) {
            if (++m[nums[right]] > k) {
                // cout << "here";
                while (left <= right && m[nums[right]] > k) {
                    --m[nums[left++]];    
                };
            };
            // cout << right  << " " << left << " : " << best << "\n";
            best = max(best, right - left + 1);
        };
        return best;
        // cout << "\n";
    };
};