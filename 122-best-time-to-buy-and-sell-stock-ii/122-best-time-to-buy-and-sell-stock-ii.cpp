class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size(), curr = 0, profit = 0, i = 0;
        while (i + 1 < n) {
            curr = nums[i];
            while (i + 1 < n && nums[i] < nums[i + 1]) i++;
            profit += (nums[i] - curr);
            i++;
        };
        return profit;
    };
};