class Solution {
public:
    void findCombination(int i, int t, int k, vector<int> nums, int n, vector<vector<int>> &ans, vector<int> ds) {
        if (t == 0) {
            if (ds.size() == k) ans.push_back(ds);
            return;
        };
        
        if (i == n || nums[i] > t || ds.size() > k) return;
        
        ds.push_back(nums[i]);
        findCombination(i + 1, t - nums[i], k, nums, n, ans, ds);
        ds.pop_back();
        findCombination(i + 1, t, k, nums, n, ans, ds);        
    };
    
    vector<vector<int>> combinationSum3 (int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> ds;        
        findCombination(0, n, k, nums, nums.size(), ans, ds);                
        return ans;
    };
};