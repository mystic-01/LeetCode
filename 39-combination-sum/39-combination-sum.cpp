class Solution {
public:
    void solve(int idx, vector<int> nums, int n, int target, vector<vector<int>>& ans, vector<int> ds) {
        if (target == 0) {
                ans.push_back(ds);
                return;
            };
        if (idx == n) {
                return;
        };
        
        if (target - nums[idx] >= 0) {
            ds.push_back(nums[idx]);
            solve(idx, nums, n, target - nums[idx], ans, ds);            
            ds.pop_back();            
        };
        solve(idx + 1, nums, n, target, ans, ds);  
    };

    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, candidates, candidates.size(), target, ans, ds);
        return ans;
    };
};