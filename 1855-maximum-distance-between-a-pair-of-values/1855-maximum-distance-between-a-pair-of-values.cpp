class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), n2 = nums2.size(), best = 0;
        int i = 0, j = 0;
        
        while (i < n) {
            while (j < n2 && nums1[i] <= nums2[j]) {
                if (i <= j) best = max(best, j - i);
                j++;
            };
            i++;
        };       
        return best;
    };
};