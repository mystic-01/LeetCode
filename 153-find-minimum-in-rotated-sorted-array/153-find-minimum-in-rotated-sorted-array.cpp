class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[hi]) hi = mid;
            else lo = mid + 1;
            cout << mid << " ";
        };
        return nums[hi];
    };
};