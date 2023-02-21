class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), lo = 0, hi = n - 1, mid = 0;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (mid + 1 < n && nums[mid] == nums[mid + 1]) {
                if (((n - 1) - mid + 1) % 2) lo = mid + 2;
                else hi = mid - 1;
            } else if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                if ((mid - 0 + 1) % 2) hi = mid - 2;
                else lo = mid + 1;
            } else return nums[mid];
        };
        return -1;
    };
};