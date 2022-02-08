class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;
        int lo = 1, hi = n - 2, i = 1;
        while (i < n - 1) {
            if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1]) return i;
            i++;
        };
        return 0;
    };
};