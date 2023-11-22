class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int row = nums.size();
        vector<int> ans;    
        map<int, vector<int>> m;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                m[i + j].push_back(nums[i][j]);
            };
        };
        for (auto &it : m) {
            for (auto vec = it.second.rbegin(); vec != it.second.rend(); ++vec) {
                ans.push_back(*vec);
            };                            
        };
        return ans;
    };
};