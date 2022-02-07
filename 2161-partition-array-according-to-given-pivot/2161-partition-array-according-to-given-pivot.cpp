class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), lo = 0, hi = n - 1, i = 0;        
        vector<int> ans(n, pivot);
        while (i < n) {
            if (nums[i] < pivot) ans[lo++] = nums[i];            
            if (nums[n - i - 1] > pivot) ans[hi--] = nums[n - i - 1];            
            i++;            
        };
        return ans;
    };
};