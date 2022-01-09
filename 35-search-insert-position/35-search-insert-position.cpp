class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (target == nums[mid]) return mid;
            else if (target < nums[mid]) hi = mid;
            else lo = mid + 1;
        };
        return hi += nums[hi] < target ? 1 : 0;
    };
};