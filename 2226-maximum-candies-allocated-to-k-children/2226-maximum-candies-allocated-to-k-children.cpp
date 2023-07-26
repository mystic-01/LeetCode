class Solution {
public:
    int maximumCandies(vector<int>& nums, long long k) {
        int n = nums.size(), ans = 0, lo = 0, hi = 1e7;
        
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo, i = 0;
            long long kDupe = k;
            
            while (kDupe > 0 && i < n) {
                if (nums[i] >= mid && mid) kDupe -= (nums[i] / mid);
                i++;
            };
            if (kDupe <= 0) ans = mid, lo = mid + 1;
            else hi = mid - 1;
        };
        
        return ans; 
    };
};