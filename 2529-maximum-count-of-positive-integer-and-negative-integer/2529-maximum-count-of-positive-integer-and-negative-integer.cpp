class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n =  nums.size(), lo = 0, hi = n - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < 0) {
                lo = mid + 1;
                if (lo == n || nums[lo] > 0) return max(lo, n - lo);
            } else if (nums[mid] > 0)  {
                hi = mid - 1;
                if (hi == -1 || nums[hi] < 0) return max(n - hi - 1, hi + 1);
            } else {
                lo = hi = mid;
                while (lo < n && nums[lo] == 0) lo++;
                while (hi >= 0 && nums[hi] == 0) hi--;
                return max(n - lo, hi + 1);
            };
        };
        return 0;
    };
};