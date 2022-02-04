class Solution {
public:
    
    void permute(int idx, vector<int> nums, int n, vector<vector<int>>&ans, vector<int>ds) {
        if (ds.size() > 1) ans.push_back(ds);
        unordered_map<int, int> m;

        for (auto i = idx; i < n; i++) {
            if ((ds.size() && nums[i] < ds.back()) || m[nums[i]]) continue;
            ds.push_back(nums[i]);
            m[nums[i]]++;
            permute(i + 1, nums, n, ans, ds);
            ds.pop_back();
        };
    };
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        unordered_map<int, int> m;        
        vector<vector<int>> ans;        
        vector<int> ds;
        permute(0, nums, nums.size(), ans, ds);
        return ans;
    };
};

// class Solution {
// public:
    
//    vector<vector<int>> findSubsequences(vector<int>& nums) {
//         vector<vector<int>> res;
//         vector<int> one;
//         find(0,nums,one,res);
//         return res;
//     }
//     void find(int p, vector<int>& nums, vector<int>& one, vector<vector<int>>& res) {
//         int n = nums.size();
//         if(one.size() > 1) res.push_back(one);
//         unordered_map<int, int> m;
        
//         for(int i = p; i < n; i++) {
//             if((i > 0 && nums[i - 1] > nums[i]) || m[nums[i]]) continue;
//             one.push_back(nums[i]);
//             m[nums[i]]++;
//             find(i+1, nums, one, res);
//             one.pop_back();
//         }
//     }
// };    