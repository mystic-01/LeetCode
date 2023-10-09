class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), found = -1, lo = 0, hi = n - 1, first = 0, last = 0;
        while (hi >= lo) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {found = mid; break;}
            else if (nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        };
        if (found == -1) return {-1, -1};
        
        lo = 0, hi = n - 1; 
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= target) hi = mid;
            else lo = mid + 1;
        };
        first = hi;
        
        lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > target) hi = mid;
            else lo = mid + 1;
        };
        if (nums[hi] != target) hi--;
        last = hi; 

        return {first, last};
    };
};