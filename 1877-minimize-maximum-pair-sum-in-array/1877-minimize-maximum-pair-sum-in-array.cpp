class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);        
        int n = nums.size(), i = 0, j = n - 1, ans = INT_MIN;
        sort(nums.begin(), nums.end());
        while (i < j) ans = max(ans, nums[i++] + nums[j--]);
        return ans;
    };
};