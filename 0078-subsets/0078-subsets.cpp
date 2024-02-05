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
        int size = nums.size(), resSize = pow(2, size);
        vector<vector<int>> result(resSize);
        for (int i = 0, x = 0, idx = 0; i < resSize; ++i, x = i, idx = 0) {
            vector<int> sub;
            for (int idx = 0; x > 0; ++idx, x >>= 1) {
                if (x & 1) sub.push_back(nums[idx]);
            };
            result[i] = sub;
        };
        return result;
    };
};

