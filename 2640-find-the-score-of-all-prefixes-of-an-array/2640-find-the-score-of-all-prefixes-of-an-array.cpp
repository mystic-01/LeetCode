class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size(), currMax = nums[0];
        vector<long long> ans(n, 0);    
    
        ans[0] = nums[0] + currMax;
        for (auto i = 1; i < n; i++) {
            currMax = max(currMax, nums[i]); 
            ans[i] += (nums[i] + currMax + ans[i - 1]);
        };
        
        return ans;
    };
};