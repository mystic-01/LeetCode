class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> answer;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums2[j] <= nums1[i]) {
                answer.push_back(nums2[j]);
                j++;
            }
            else {
                answer.push_back(nums1[i]);
                i++;
            };
        };
        while (j < n) {
            answer.push_back(nums2[j]);
            j++;
        };
        while (i < m) {
            answer.push_back(nums1[i]);
            i++;
        };
        nums1 = answer;
    };
};