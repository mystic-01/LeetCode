class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int n = nums.size(), lo = 1, hi = *max_element(nums.begin(), nums.end());
        if (h < n) return -1;
        if (h == n) return hi;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int tHours = 0;
            for (auto i : nums) tHours += ceil(double(i) / mid);
            if (tHours <= h) hi = mid;
            else lo = mid + 1;
        };
        return hi;
    };
};