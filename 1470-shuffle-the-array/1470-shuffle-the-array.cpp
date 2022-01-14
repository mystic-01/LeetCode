class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = 0, j = n, k = 0;
        vector<int> ans(2 * n);
        while (i < n && j < 2 * n) ans[k++] = (k % 2 == 0) ? nums[i++] : nums[j++];
        while (i < n) ans[k++] = nums[i++];
        while (j < 2 * n) ans[k++] = nums[j++];
return ans;
    };
};