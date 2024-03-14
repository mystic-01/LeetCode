class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        multiset<int> ms(begin(nums1), end(nums1));
        
        for (int i = 0; i < n; ++i) {
            auto smallestGreater = ms.upper_bound(nums2[i]);
            if (smallestGreater == ms.end())  {
                smallestGreater = begin(ms);
            };
            nums1[i] = *smallestGreater;
            ms.erase(smallestGreater);
        };
        return nums1;
    };
};