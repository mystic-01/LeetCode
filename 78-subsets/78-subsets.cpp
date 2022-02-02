// class Solution {
// public:
    
//     void subsequences(int i, vector<int> nums, int n, vector<vector<int>> & ans, vector<int> ds) {
//         if (i == n) {
//             ans.push_back(ds);
//             return;
//         };
//         ds.push_back(nums[i]);
//         subsequences(i + 1, nums, n, ans, ds);
//         ds.pop_back();    
//         subsequences(i + 1, nums, n, ans, ds);
//     };
    
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans;            
//         vector<int> ds;            
//         subsequences(0, nums, nums.size(), ans, ds);
//         return ans;
//     };
// };

class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;            
        result.push_back({});
        for (auto n : nums) {
            int size = result.size();
            for(auto i = 0; i < size; i++) {
                vector<int> subset = result[i];
                subset.push_back(n);
                result.push_back(subset);
            };
        };
        return result;
    };
};

