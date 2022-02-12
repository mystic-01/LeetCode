class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n = nums.size(), h = 0, lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > n - mid) {
                hi = mid - 1;
                h = max(h, n - mid);
            } else if (nums[mid] < n - mid) {
                lo = mid + 1;
                h = max(h, nums[mid]);                
            } else return nums[mid];            
        };
        return h;
    };
};