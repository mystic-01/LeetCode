class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), pos = 0, neg = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                while (pos < n && nums[pos] < 0) {
                    ++pos;    
                };
                ans[i] = nums[pos++];
            } else {
                while (neg < n && nums[neg] >= 0) {
                    ++neg;
                };
                ans[i] = nums[neg++];
            }; 
        };
        return ans;
    };
};