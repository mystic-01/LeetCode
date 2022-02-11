class Solution {
public:
    int binarySearch (int l, int r, vector<int> nums, int target) {
        while (r >= l) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        };
        return - 1;
    };
    
    int lowerBound (vector<int> nums, int target) {
        int lo = 0, hi = nums.size() - 1; 
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
             if (nums[mid] >= target) hi = mid;
             else lo = mid + 1;
        };
        return hi;
    };
    
    int upperBound (vector<int> nums, int target) {
        int lo = 0, hi = nums.size() - 1; 
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
             if (nums[mid] > target) hi = mid;
             else lo = mid + 1;
        };
        return hi;
    };
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), foundTarget = binarySearch (0, n - 1, nums, target);
        if (foundTarget == -1) return {-1, -1};
        int i1 = lowerBound(nums, target), i2 = upperBound(nums, target);
        i2 -= nums[i2] != target ? 1 : 0; 
        return {i1, i2};
    };
};