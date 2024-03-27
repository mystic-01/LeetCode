class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size(), sum = 0;
        vector<int> ans(q, 0);
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 0) {
                sum += nums[i];            
            };
        };
        for (int i = 0; i < q; ++i) {
            int val = queries[i][0], idx = queries[i][1];  
            if (nums[idx] % 2 == 0) {
                sum -= nums[idx];            
            };
            nums[idx] += val;
            if (nums[idx] % 2 == 0) {
                sum += nums[idx];
            };
            ans[i] = sum;
        };
        return ans;
    };
};