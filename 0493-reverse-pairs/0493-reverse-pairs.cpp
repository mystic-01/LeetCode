class Solution {
public:
    int merge(int lo, int mid, int hi, vector<int> &nums, vector<int> &temp) {
        int count = 0, i = lo, j = mid + 1, k = lo;
        while (i <= mid && j <= hi) {
            if (nums[i] > nums[j] * 2LL) {
                count += (mid - i + 1);    
                j++;
            } else {
                i++;
            };    
        };
        i = lo, j = mid + 1;
        
        while (i <= mid && j <= hi) {
            temp[k++] = nums[i] > nums[j] ? nums[j++] : nums[i++];    
        };
        
        while (i <= mid) {
            temp[k++] = nums[i++];    
        };
        
        while (j <= hi) {
            temp[k++] = nums[j++];                    
        };
        
        for (int l = lo; l <= hi; l++) {
            nums[l] = temp[l];
        };
        return count;
    };
    
    int mergeSort(int lo, int hi, vector<int> &nums, vector<int> &temp) {
        int count = 0;
        if (lo < hi) {
            int mid = (hi - lo) / 2 + lo;
            count += mergeSort(lo, mid, nums, temp);
            count += mergeSort(mid + 1, hi, nums, temp);

            count += merge(lo, mid, hi, nums, temp);
        };
        return count;
    };
    
    
    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        vector<int> temp(n);
        return mergeSort(0, n - 1, nums, temp);
    };
};