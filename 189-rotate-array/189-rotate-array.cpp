class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);        
        
        int n = nums.size();
        if (n == 1) return;
        vector<int> ans(n);
        
        k = k % n;
        int x =  k == 0 ? 0 : n - k, i = 0;

        while(i < n) {
            ans[i++] = nums[x++];
            x = x == n ? 0 : x;
        }
        nums = ans;
    };
};