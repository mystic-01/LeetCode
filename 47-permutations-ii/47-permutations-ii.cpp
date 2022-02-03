class Solution {
public:
    void permutator(int idx, vector<int> nums, int n, vector<vector<int>> & ans) {
        if (idx == n) ans.push_back(nums);
        
        for (auto i = idx; i < n; i++) {
            if (i > idx && nums[idx] == nums[i]) continue;
            swap(nums[i], nums[idx]);
            permutator(idx + 1, nums, n, ans);
            // swap(nums[i], nums[idx]);
        };
    };
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        permutator(0, nums, nums.size(), ans);
        return ans;
    };
};