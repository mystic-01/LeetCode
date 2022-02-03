class Solution {
public:
    void permutator(vector<int>nums, int n, vector<vector<int>>&ans, unordered_map<int,int>m,vector<int>ds) {
        if (ds.size() == n) {
            ans.push_back(ds);
            return;
        };
        for (auto i = 0; i < n; i++) {
            if (m[nums[i]] == 1) continue;
            ds.push_back(nums[i]);
            m[nums[i]]++;
            permutator(nums, n, ans, m, ds);
            ds.pop_back();
            m[nums[i]]--;
        };
    };    

    
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<vector<int>> ans;
        vector<int> ds;
        permutator(nums, nums.size(), ans, m, ds);    
        return ans;
    };
};
