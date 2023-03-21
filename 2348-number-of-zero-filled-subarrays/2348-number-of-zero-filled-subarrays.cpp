class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size(), zeros = 0;
        long long ans = 0;
        
        for (auto i = 0; i < n; i++) {
            if (nums[i] != 0) zeros = 0;
            else zeros++, ans += zeros;
        };
        
        return ans;
    };
};