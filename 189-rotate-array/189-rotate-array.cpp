class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);        

        int n = nums.size();
        k %= n;

        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    };
};