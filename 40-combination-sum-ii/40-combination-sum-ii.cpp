class Solution {
public:
    void findCombination (int index, int target, vector<int> nums, int n, vector<vector<int>>& ans, vector<int> ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        };
        
        for (auto i = index; i < n; i++) {
            if (i > index && nums[i - 1] == nums[i]) continue;
            if (nums[i] > target) break;
            ds.push_back(nums[i]);
            findCombination(i + 1, target - nums[i], nums, n, ans, ds);          
            ds.pop_back();        
        };
    };
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;                
        vector<int> ds;
        findCombination(0, target, nums, nums.size(), ans, ds);
        return ans;
    };
};