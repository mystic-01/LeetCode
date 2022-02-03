// class Solution {
// public:
//     void permutator(vector<int>nums, int n, vector<vector<int>>&ans, unordered_map<int,int>m,vector<int>ds) {
//         if (ds.size() == n) {
//             ans.push_back(ds);
//             return;
//         };
//         for (auto i = 0; i < n; i++) {
//             if (m[nums[i]] == 1) continue;
//             ds.push_back(nums[i]);
//             m[nums[i]]++;
//             permutator(nums, n, ans, m, ds);
//             ds.pop_back();
//             m[nums[i]]--;
//         };
//     };    

    
//     vector<vector<int>> permute(vector<int>& nums) {
//         unordered_map<int, int> m;
//         vector<vector<int>> ans;
//         vector<int> ds;
//         permutator(nums, nums.size(), ans, m, ds);    
//         return ans;
//     };
// };

class Solution {
public:
    void permutator(int idx, vector<int> nums, int n, vector<vector<int>>& ans) {
        if (idx == n) {
            ans.push_back(nums);
            return;
        };
        for (auto i = idx; i < n; i++) {
            swap(nums[i], nums[idx]);
            permutator(idx + 1, nums, n, ans);
            swap(nums[i], nums[idx]);
        };
    };    

    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutator(0, nums, nums.size(), ans);    
        return ans;
    };
};
