class Solution {
public:
    int maxCoins(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size(), ans = 0, count = n / 3, i = 1;

        while (count > 0) ans += (nums[i]), count--, i += 2;
        return ans;
    };
};