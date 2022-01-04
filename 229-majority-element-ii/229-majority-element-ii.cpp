class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size(), golden = (n / 3) + 1;
        int nums1 = -1, nums2 = -1, count1 = 0, count2 = 0;
        for (auto i = 0; i < n; i++) {
            if (nums1 == nums[i]) {
                count1++;
            } else if (nums2 == nums[i]) {
                count2++;
            } else if (count1 == 0) {
                nums1 = nums[i];
                count1++;
            } else if (count2 == 0) {
                nums2 = nums[i];
                count2++;
            } else {
                count1--;                
                count2--;
            }
        };
        count1 = 0, count2 = 0;
        for (auto i = 0; i < n; i++) {
            if (nums1 == nums[i]) count1++;
            else if (nums2 == nums[i]) count2++;
        };        
        if (count1 >= golden) ans.push_back(nums1);
        if (count2 >= golden) ans.push_back(nums2);
        return ans;
    };
};