class Solution {
public:
    int merge(int lo, int mid, int hi, vector<long> &pre, vector<long> &temp, int &lower, int &upper) {
        int count = 0, i = lo, j = mid + 1, k = lo, j1 = j, j2 = j;
        for (int i = lo; i <= mid; ++i) {
            while (j1 <= hi && pre[j1] - pre[i] < lower) ++j1;    
            while (j2 <= hi && pre[j2] - pre[i] <= upper) ++j2;
            count += (j2 - j1);
        };
        
        while (i <= mid && j <= hi) {
            temp[k++] = pre[i] > pre[j] ? pre[j++] : pre[i++];    
        };
        
        while (i <= mid) {
            temp[k++] = pre[i++];    
        };
        
        while (j <= hi) {
            temp[k++] = pre[j++];                    
        };
        
        for (int l = lo; l <= hi; l++) {
            pre[l] = temp[l];
        };
        return count;
    };
    
    int mergeSort(int lo, int hi, vector<long> &pre, vector<long> &temp, int &lower, int &upper) {
        int count = 0;
        if (lo < hi) {
            int mid = (hi - lo) / 2 + lo;
            count += mergeSort(lo, mid, pre, temp, lower, upper);
            count += mergeSort(mid + 1, hi, pre, temp, lower, upper);
            count += merge(lo, mid, hi, pre, temp, lower, upper);
        };
        return count;
    };
    
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> temp(n + 1), pre(n + 1, 0);
        for (int l = 1; l <= n; l++) {
            pre[l] = nums[l - 1] + pre[l - 1];
        };
        return mergeSort(0, n, pre, temp, lower, upper);
    };
};