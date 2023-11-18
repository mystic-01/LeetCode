class Solution {
public:
    void merge(int lo, int mid, int hi, vector<pair<int, int>> &nums, vector<pair<int, int>> &temp, vector<int> &ans) {
        int i = lo, j = mid + 1, k = lo;
        while (i <= mid && j <= hi) {
            if (nums[i].first > nums[j].first) {
                ans[nums[i].second] += (hi - j + 1);
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            };                
        };
        
        while (i <= mid) {
            temp[k++] = nums[i++];
        };

        while (j <= hi) {
            temp[k++] = nums[j++];                
        };  
        
        for (int l = lo; l <= hi; ++l) {
            nums[l] = temp[l];    
        };
    };
    
    void mergeSort(int lo, int hi, vector<pair<int, int>> &nums, vector<pair<int, int>> &temp, vector<int> &ans) {
        if (lo < hi) {
            int mid = (hi - lo) / 2 + lo;
            mergeSort(lo, mid, nums, temp, ans);
            mergeSort(mid + 1, hi, nums, temp, ans);
            merge(lo, mid, hi, nums, temp, ans);            
        };        
    };
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int, int>> numsWithIdx(n), temp(n);
        for (int i = 0; i < n; ++i) {
            numsWithIdx[i] = {nums[i], i};    
        };
        mergeSort(0, n - 1, numsWithIdx, temp, ans);
        return ans;
    };
};