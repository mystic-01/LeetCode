class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size(), smallest = 2147483647, small = 2147483647;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < small) {
                if (nums[i] < smallest) {
                    small = smallest;
                    smallest = nums[i];
                } else {
                    small = nums[i];
                };            
            };
        };
        return nums[0] + smallest + small;
    };
};