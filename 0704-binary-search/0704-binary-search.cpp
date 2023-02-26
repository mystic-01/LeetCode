class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        
        while (lo <= hi) {
            if (lo == hi) return nums[lo] == target ? lo : -1;
            int mid = lo + (hi - lo) / 2;            
            if (target == nums[mid]) return mid;
            else if (target > nums[mid]) lo = mid + 1;
            else hi = mid;
        };
        
        return -1;
    };
};