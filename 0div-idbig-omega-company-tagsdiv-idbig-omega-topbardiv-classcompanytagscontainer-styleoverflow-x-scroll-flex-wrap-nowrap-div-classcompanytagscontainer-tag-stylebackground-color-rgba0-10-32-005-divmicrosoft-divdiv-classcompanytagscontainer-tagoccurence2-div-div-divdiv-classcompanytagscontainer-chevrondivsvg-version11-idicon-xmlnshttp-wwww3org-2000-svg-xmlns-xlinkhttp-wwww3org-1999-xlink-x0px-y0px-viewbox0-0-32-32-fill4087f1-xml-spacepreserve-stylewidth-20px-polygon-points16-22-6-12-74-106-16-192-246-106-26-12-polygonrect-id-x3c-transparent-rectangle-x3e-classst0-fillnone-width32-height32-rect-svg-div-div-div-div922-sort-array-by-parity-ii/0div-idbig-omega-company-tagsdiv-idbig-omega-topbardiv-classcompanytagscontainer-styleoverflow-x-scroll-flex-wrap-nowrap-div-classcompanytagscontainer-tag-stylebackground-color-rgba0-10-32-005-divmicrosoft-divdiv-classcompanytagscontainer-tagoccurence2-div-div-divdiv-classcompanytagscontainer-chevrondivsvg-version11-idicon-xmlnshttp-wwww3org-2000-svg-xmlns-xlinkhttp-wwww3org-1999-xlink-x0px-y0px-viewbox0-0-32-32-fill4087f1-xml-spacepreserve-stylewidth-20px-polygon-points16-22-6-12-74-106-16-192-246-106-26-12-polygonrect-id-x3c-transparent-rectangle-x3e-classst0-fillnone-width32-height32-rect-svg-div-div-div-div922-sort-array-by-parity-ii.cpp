class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for (int i = 0, j = 1; i < nums.size();) {
            while (i < nums.size() && i % 2 == nums[i] % 2) i += 2;
            while (j < nums.size() && j % 2 == nums[j] % 2) j += 2;
            if (i < nums.size()) swap(nums[i], nums[j]);
        };  
        return nums;
    };
};