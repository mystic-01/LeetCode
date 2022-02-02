class Solution {
public:
    
    void subsequences(int i, vector<int> nums, int n, vector<vector<int>> & ans, vector<int> ds) {
        if (i == n) {
            ans.push_back(ds);
            return;
        };
        ds.push_back(nums[i]);
        subsequences(i + 1, nums, n, ans, ds);
        ds.pop_back();    
        subsequences(i + 1, nums, n, ans, ds);
    };
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;            
        vector<int> ds;            
        subsequences(0, nums, nums.size(), ans, ds);
        return ans;
    };
};