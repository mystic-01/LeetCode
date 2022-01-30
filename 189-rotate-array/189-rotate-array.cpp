class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);        

        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    };
};