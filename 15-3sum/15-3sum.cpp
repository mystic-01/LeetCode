class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        vector<vector<int>> threesome;
        
        int i = 0, n = nums.size() - 1;
        while (i < n - 1) {
            int a = nums[i], lo = i + 1, hi = n;
            while (lo < hi) {
                int b = nums[lo], c = nums[hi];
                if (a + b == 0 - c) {
                    threesome.push_back({a, b, c});
                    while (nums[lo] == b && lo < n) lo++;
                    while (nums[hi] == c && hi > 0) hi--;
                } else if (a + b < 0 - c) while (nums[lo] == b && lo < n) lo++;
                else while (nums[hi] == c && hi > 0) hi--;
            };
            while (nums[i] == a && i < n) i++;
        };
        return threesome;
    };
};