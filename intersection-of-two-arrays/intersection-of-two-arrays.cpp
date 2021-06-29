class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> answer;
        int s1 = nums1.size(), s2 = nums2.size();
        if (s1 < s2) {
            for (int i = 0; i < s1; i++) {
                auto it = find(nums2.begin(), nums2.end(), nums1[i]);
                if (it != nums2.end()) answer.insert(nums1[i]);
            };    
        } else {
            for (int i = 0; i < s2; i++) {
                auto it = find(nums1.begin(), nums1.end(), nums2[i]);
                if (it != nums1.end()) answer.insert(nums2[i]);
            };    
        };
        vector<int> v(answer.begin(), answer.end());
        return v;
    };
};