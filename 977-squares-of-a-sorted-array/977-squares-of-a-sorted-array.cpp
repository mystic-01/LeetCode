class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        int n = 0, p = 0, k = 0, size = nums.size() - 1;
        vector<int> ans(size + 1);

        while(p <= size && nums[p] < 0) p++;
        n = p - 1;
        
        while (n >= 0 && p <= size) 
            ans[k++] = (pow((-1 * nums[n] > nums[p]) ? nums[p++] : nums[n--], 2));
        
        while (n >= 0)
            ans[k++] = (pow(nums[n--], 2));

        while (p <= size) 
            ans[k++] = (pow(nums[p++], 2));

        return ans;
    };
};