class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            if (nums[mid] < nums[mid + 1]) lo = mid + 1;
            else if (nums[mid] < nums[mid - 1]) hi = mid - 1;
            else return mid;
        };
        return -1;
    };
};