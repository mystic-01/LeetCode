class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), found = -1, first = 0, last = 0;
        int l = 0, r = n - 1;
        while (r >= l) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {found = mid; break;}
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        };
        if (found == -1) return {-1, -1};
        
        int lo = 0, hi = n - 1; 
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