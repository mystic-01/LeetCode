class Solution {
public:
    int maximumCandies(vector<int>& nums, long long k) {
        int n = nums.size(), ans = 0, lo = 1, hi = 1e7;
        
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            long long kDupe = k;
            for (int i = 0; kDupe > 0 && i < n; i++) {
                kDupe -= (nums[i] / mid);
            };
            if (kDupe <= 0) ans = mid, lo = mid + 1;
            else hi = mid - 1;
        };
        
        return ans;
    };
};