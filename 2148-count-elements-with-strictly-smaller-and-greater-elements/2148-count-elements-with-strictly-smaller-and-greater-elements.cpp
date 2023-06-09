class Solution {
public:
    int countElements(vector<int>& nums) {
        int minimum = *min_element(nums.begin(), nums.end());
        int maximum = *max_element(nums.begin(), nums.end());
        
        int n = nums.size(), i = 0, count = n;
        while (i < n) {
            if (nums[i] == minimum || nums[i] == maximum) count--;
            i++;
        };
        return count;
    };
};