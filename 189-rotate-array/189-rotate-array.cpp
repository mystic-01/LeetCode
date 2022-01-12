class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);        

        int n = nums.size();
        if (k == 0 || n == 1) return;
        k %= n;

        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
        
//         if (n == 1) return;
//         vector<int> ans(n);
        
//         int x = n - k, i = 0;

//         while(i < n) {
//             ans[i++] = nums[x++];
//             x = x == n ? 0 : x;
//         }
//         nums = ans;
    };
};