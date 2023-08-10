class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size(), minDiff = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 1; i++) {
            int diff = abs(nums[i] - nums[i + 1]);
            if (diff <= minDiff) {
                if (diff < minDiff) {
                    ans.clear();
                    minDiff = abs(nums[i] - nums[i + 1]);
                };
                ans.push_back({nums[i], nums[i + 1]});                
            };
        };
        
        return ans;
    };
};