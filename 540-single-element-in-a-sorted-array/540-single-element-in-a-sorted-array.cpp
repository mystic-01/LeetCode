class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid > 0 && nums[mid - 1] == nums[mid]) {
                int len = mid - lo +  1;
                if (len % 2) hi = mid;
                else lo = mid + 1;
            } else if (mid < n - 1 && nums[mid] == nums[mid + 1]) {
                int len = hi - mid + 1;
                if (len % 2) lo = mid;
                else hi = mid - 1;
            } else {
                return nums[mid];    
            };
        };
        return -1;
    };
};