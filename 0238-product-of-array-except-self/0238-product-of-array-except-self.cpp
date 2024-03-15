class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), product = 1, zeroCount = 0;
        vector<int> ans(n, 0);      
        for (int i = 0; i < n; ++i) {
            if (nums[i]) {
                product *= nums[i];                
            } else {
                ++zeroCount;
            };
        };
        
        if (zeroCount <= 1) {
            for (int i = 0; i < n; ++i) {
                if (nums[i]) {
                    if (zeroCount == 0) {
                        ans[i] = product / nums[i];
                    };
                } else {
                    ans[i] = product;
                };
            };            
        };
        return ans;
    };
};