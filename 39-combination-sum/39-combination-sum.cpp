class Solution {
public:
    
    void findCombination(int i, vector<int> nums, int target, int n, vector<vector<int>> & ans, vector<int> ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        };
        
        if (i == n) return;
        
        if (nums[i] <= target) {
            ds.push_back(nums[i]);
            findCombination(i, nums, target - nums[i], n, ans, ds);
            ds.pop_back();
        };
        findCombination(i + 1, nums, target, n, ans, ds);
    };

    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {   
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, nums, target, nums.size(), ans, ds);
        return ans;
    };
};