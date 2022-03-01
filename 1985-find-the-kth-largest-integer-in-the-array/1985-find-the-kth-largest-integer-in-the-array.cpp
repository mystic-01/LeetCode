class Solution {
public:
    static bool comp (string a, string b) {
        int l1 = a.length(), l2 = b.length();
        if (l1 == l2) {
            for (auto i = 0; i < l1; i++) {
                if (a[i] == b[i]) continue;
                return a[i] > b[i];            
            };
        };
        return l1 > l2;
    };
    
    void merge(int l, int mid, int r, vector<string>& nums) {
        int i = l, j = mid;
        
        vector<string> temp;
        while (i <= mid - 1 && j <= r)
            temp.push_back(comp(nums[i], nums[j]) ? nums[i++] : nums[j++]);                        

        while (i <= mid - 1)
            temp.push_back(nums[i++]);                        

        while (j <= r)
            temp.push_back(nums[j++]);    
        
        for (auto i = l; i <= r; i++) 
            nums[i] = temp[i - l];
    };
    
    void mergeSort(int l, int r, vector<string>& nums) {
        if (r > l) {
            int mid = l + (r - l) / 2;
            mergeSort(l, mid, nums);
            mergeSort(mid + 1, r, nums);

            merge(l, mid + 1, r, nums);
        };        
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        mergeSort(0, n - 1, nums);
        return nums[k - 1];
    };
};