class Solution {
public:
    int merge(int l, int r, int mid, vector<int> &arr) {
        int i = l, j = mid, count = 0;
        while (i < mid) {
            while (j <= r && arr[i] > 2LL * arr[j]) j++;
            count += (j - mid);
            i++;
        };

        i = l, j = mid;
        vector<int> temp;
        while ((i <= mid -1) && (j <= r))
            temp.push_back(arr[i] < arr[j] ? arr[i++] : arr[j++]);
        
        while (i <= mid -1)
            temp.push_back(arr[i++]);
        
        while (j <= r)
            temp.push_back(arr[j++]);
        
        for (int i = l; i <= r; i++)
            arr[i] = temp[i - l];
        
        return count;
    };

    int mergeSort(int l, int r, vector<int> &arr) {
        int count = 0;
        if (r > l) {
            int mid = (r + l) / 2;
            count += mergeSort(l, mid, arr);
            count += mergeSort(mid + 1, r, arr);
            
            count += merge(l, r, mid + 1, arr);
        };
        return count;
    };

    int reversePairs(vector<int>& nums) {
        int n = nums.size(), count = 0;
        // vector<int> temp(n);
        // for (int i = 0; i < n - 1; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         double a = (double)nums[i] / 2, b = nums[j];
        //         if (a > b) count++;
        //     };
        // };
        // return count;
        return mergeSort(0, n - 1, nums);      
    };
};