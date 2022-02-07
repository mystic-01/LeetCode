class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), lo = 0, hi = n - 1, i = 0, j = n - 1;  
        // Fill constructor supremacy        
        vector<int> ans(n, pivot);
        while (i < n) {
            if (nums[i] < pivot) ans[lo++] = nums[i];            
            if (nums[j] > pivot) ans[hi--] = nums[j];            
            i++;            
            j--;
        };
        return ans;
    };
};