class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        
        int n = nums.size(), lo = 0, hi = n - 1, mid = 0;
        
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (target == nums[mid]) return mid;
            else if (target < nums[mid]) hi = mid;
            else lo = mid + 1;
        };
        
        return target > nums[n - 1] ? n : target < nums[0] ? 0 : hi;
    };
};