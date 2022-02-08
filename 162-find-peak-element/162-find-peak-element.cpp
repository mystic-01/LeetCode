class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid + 1 < n && nums[mid] < nums[mid + 1]) lo = mid + 1;
            else if (mid - 1 > -1 && nums[mid] < nums[mid - 1]) hi = mid - 1;
            else return mid;
        };
        return hi;
    };
};
