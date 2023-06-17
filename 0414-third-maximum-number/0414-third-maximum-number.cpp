class Solution {
private:
    void merge(int lo, int mid, int hi, vector<int> &nums, vector<int> &temp) {
        int k = lo, i = lo, j = mid + 1;
        
        while (i <= mid && j <= hi) {
            temp[k++] = nums[i] > nums[j] ? nums[i++] : nums[j++];                     
        };
        
        while (i <= mid) {
            temp[k++] = nums[i++];                            
        };
        
        while (j <= hi) {
            temp[k++] = nums[j++];                           
        };

        for (auto i = lo; i <= hi; i++) nums[i] = temp[i];
    };    
    
    void mergeSort(int lo, int hi, vector<int> &nums, vector<int> &temp) {
        if (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            mergeSort(lo, mid, nums, temp);
            mergeSort(mid + 1, hi, nums, temp);

            merge(lo, mid, hi, nums, temp);
        };
    };
    
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        mergeSort(0, n - 1, nums, temp);
        
        int best = nums[0], count = 1;
        
        for (auto i = 0; i < n; i++) {
            if (nums[i] < best) {
                best = nums[i];
                if (++count == 3) return best;
            };
        };
        return nums[0];
    };
};