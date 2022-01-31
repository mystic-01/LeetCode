class Solution {
public:
    
//     void merge (int l, int mid, int r, vector<int>& nums, int temp[]) {
//         int i = l, j = mid + 1, k = l;
        
//         while (i <= mid && j <= r) temp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];

//         while (i <= mid) temp[k++] = nums[i++];
        
//         while (j <= r) temp[k++] = nums[j++];
        
//         for (auto i = l; i <= r; i++) nums[i] = temp[i];
        
//     };
    
//     void mergeSort (int l, int r, vector<int>& nums, int temp[]) {
//         if (r > l) {
//             int mid = l + (r - l) / 2;
//             mergeSort (l, mid, nums, temp);            
//             mergeSort (mid + 1, r, nums, temp);            
            
//             merge (l, mid, r, nums, temp);            
//         };
//     };
    
    vector<int> sortArray(vector<int>& nums) {
        // int n = nums.size(), temp[n]; 
        // mergeSort(0, n - 1, nums, temp);   
        sort(nums.begin(),nums.end());
        return nums;
    };
};