class Solution {
public:
    auto lowerBound(int target, set<int> s) {
        auto lo = s.begin(), hi = s.end(), it = s.begin();
        
        if (target < *lo) return lo;
        int count = distance(lo, hi);        
        while (count > 0) {
            it = lo;
            int mid = count / 2;
            if (*it < target) {
                lo = ++it;
                count -= mid + 1;
            } else {
                count = mid;
            };
        };
        return lo;
    };
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s;
        for (auto i = 0; i < nums.size(); i++) {
            if (i > k) s.erase(nums[i - k - 1]);
            if (s.size()) {
                auto pos = s.lower_bound((long)nums[i] - t);
                if (pos != s.end() && *pos - (long)nums[i] <= t) return 1;
            };
            s.insert(nums[i]);
        };
        return 0;
    };
};