class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size(), lo = 0, hi = n - 1;        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[mid + 1]) lo = mid + 1;
            else if (nums[mid] < nums[mid - 1]) hi = mid - 1;
            else return mid;
        };
        return hi;
    };
};