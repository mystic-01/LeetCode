class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size(), gradient = 0;
        for (int i = 1; i < n; ++i){ 
            if (nums[i] > nums[i - 1]) {
                if (gradient == -1) return false;
                else gradient = 1;
            } else if (nums[i] < nums[i - 1]) {
                if (gradient == 1) return false;
                else gradient = -1;
            };
        };
        return true;
    };
};