class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > max1) {
                max1 = nums[i];
            };
            if (max1 > max2) {
                swap(max1, max2);
            };
        };
        return (max1 - 1) * (max2 - 1);
    };
};