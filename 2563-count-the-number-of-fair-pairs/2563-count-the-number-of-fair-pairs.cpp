class Solution {
public:
    long long merge(int lo, int mid, int hi, vector<int> &nums, vector<int> &temp, int &lower, int &upper) {
        long long count = 0;
        int i = lo, j = mid + 1, k = lo, i1 = i, i2 = i;        

        for (int j = mid + 1; j <= hi; ++j) {
            auto i1 = lower_bound(nums.begin() + lo, nums.begin() + mid + 1, lower - (long)nums[j]);
            auto i2 = upper_bound(nums.begin() + lo, nums.begin() + mid + 1, upper - (long)nums[j]);
            count += (i2 - i1);
        };
        
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
    
    long long mergeSort(int lo, int hi, vector<int> &nums, vector<int> &temp, int &lower, int &upper) {
        long long count = 0;
        if (lo < hi) {
            int mid = (hi - lo) / 2 + lo;
            count += mergeSort(lo, mid, nums, temp, lower, upper);
            count += mergeSort(mid + 1, hi, nums, temp, lower, upper);

            count += merge(lo, mid, hi, nums, temp, lower, upper);
        };
        return count;
    };
    
    long long countFairPairs(vector<int>& nums, int &lower, int &upper) {
        int n = nums.size();
        vector<int> temp(n);
        return mergeSort(0, n - 1, nums, temp, lower, upper);
    };
};
