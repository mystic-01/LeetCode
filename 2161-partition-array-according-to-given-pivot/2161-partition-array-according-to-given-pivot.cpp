class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), lo = 0, hi = n - 1;
        vector<int> ans(n, pivot);
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) ans[lo++] = nums[i];            
            if (nums[n - i - 1] > pivot) ans[hi--] = nums[n - i - 1];            
        };
        return ans;
    };
};