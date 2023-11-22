class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int row = nums.size(), maxVal = 0;
        for (int i = 0; i < row; ++i) {
            maxVal = max(maxVal, i + (int)nums[i].size() - 1);
        };
        
        vector<int> ans;    
        vector<vector<int>> vec(maxVal + 1);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                vec[i + j].push_back(nums[i][j]);
            };
        };
        for (auto &it : vec) {
            for (auto iter = it.rbegin(); iter != it.rend(); ++iter) {
                ans.push_back(*iter);
            };                            
        };
        return ans;
    };
};