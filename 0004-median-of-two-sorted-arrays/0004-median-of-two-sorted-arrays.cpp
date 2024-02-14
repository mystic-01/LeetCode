class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     // TODO!!!   
        int n1 = nums1.size(), n2 = nums2.size(), totSize = n1 + n2, sizeBy2 = totSize / 2;
        // cout << "\n\n";
        if (n1 > n2) {
            swap(nums1, nums2);
            swap(n1, n2);
        };
        int lo = 0, hi = n1;
        while (lo <= hi) {
            int mid1 = (hi - lo) / 2 + lo;
            int mid2 = sizeBy2 - mid1;
            int l1 = INT_MIN, r1 = INT_MAX, l2 = INT_MIN, r2 = INT_MAX;
            // cout << lo << " " << hi << " : " << mid1 << " " << mid2 << "      \t";
            if (mid1 - 1 >= 0) {
                l1 = nums1[mid1 - 1];                
            };
            if (mid2 - 1 >= 0) {
                l2 = nums2[mid2 - 1];                
            };            
            if (mid1 < n1) {
                r1 = nums1[mid1];
            };            
            if (mid2 < n2) {
                r2 = nums2[mid2];
            };
            
            // cout << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
            if (l1 > r2) {
                hi = mid1 - 1;
            } else if (r1 < l2) {
                lo = mid1 + 1;
            } else {
                if (totSize % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;                        
                } else {
                    return min(r1, r2);
                };
            };  
        };
        return -69;
    };
};