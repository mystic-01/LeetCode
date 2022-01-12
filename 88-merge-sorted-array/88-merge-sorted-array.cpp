class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);        
        
        if (m == 0) nums1 = nums2;
        int i = m - 1, j = n - 1, k = m + n - 1;
        
        while(i >= 0 && j >= 0)
            nums1[k--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];                       
        
        while(j >= 0) 
            nums1[k--] = nums2[j--];                       
    };
};
