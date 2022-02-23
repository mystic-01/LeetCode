class Solution {
public:
    int merge(int l, int r, int mid, vector<int> &nums) {
        int i = l, j = mid, count = 0;
        while (i <= mid - 1) {
            while (j <= r && nums[i] > 2LL * nums[j]) j++;
            count += (j - mid);
            i++;
        };

        i = l, j = mid;
        vector<int> temp;
        while (i <= mid - 1 && j <= r)
            temp.push_back(nums[i] < nums[j] ? nums[i++] : nums[j++]);
        
        while (i <= mid -1)
            temp.push_back(nums[i++]);
        
        while (j <= r)
            temp.push_back(nums[j++]);
        
        for (int i = l; i <= r; i++)
            nums[i] = temp[i - l];
        
        return count;
    };

    int mergeSort(int l, int r, vector<int> &arr) {
        int count = 0;
        if (r > l) {
            int mid = (l + r) / 2;
            count += mergeSort(l, mid, arr);
            count += mergeSort(mid + 1, r, arr);
            
            count += merge(l, r, mid + 1, arr);
        }; 
        return count;
        
    };

    int reversePairs(vector<int>& nums) {
        return mergeSort(0, nums.size() - 1, nums);      
    };
};