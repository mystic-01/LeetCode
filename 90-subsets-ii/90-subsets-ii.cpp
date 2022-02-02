class Solution {
public:
    void subSequences(int idx, vector<int> nums, int n, vector<vector<int>> & ans, vector<int> ds) {
        ans.push_back(ds);
        
        for (int i = idx; i < n; i++) {
            if (i > idx && nums[i - 1] == nums[i]) continue;            
            ds.push_back(nums[i]);
            subSequences(i + 1, nums, n, ans, ds);
            ds.pop_back();
        };
    };

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ds;        
        vector<vector<int>> ans;        
        subSequences(0, nums, nums.size(), ans, ds);
        return ans;
    };
};