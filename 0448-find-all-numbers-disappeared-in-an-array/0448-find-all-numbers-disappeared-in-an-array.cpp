// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         int n = nums.size(), start = 0;
//         vector<int> ans(n);            
//         for (int i = 0; i < n; i++) {
//             ans[i] = i + 1;
//         };
        
//         for (int i = 0; i < n; i++) {
//             ans[nums[i] - 1] = -1;                                
//         };
        
//         for (int i = 0; i < n; i++) {
//             if (ans[i] != -1) ans[start++] = ans[i];
//         };
//         ans.erase(ans.begin() + start, ans.end());
//         return ans;
//     };
// };

// True O(1) Extra Space

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size(), start = 0;
        vector<int> ans;            
        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            nums[idx] = -1 * abs(nums[idx]);
        };
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) ans.push_back(i + 1);                                
        };
        return ans;
    };
};