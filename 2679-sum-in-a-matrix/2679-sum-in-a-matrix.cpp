class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int row = nums.size(), col = nums[0].size(), score = 0;
        for (int i = 0; i < row; ++i) {
            sort(begin(nums[i]), end(nums[i]), greater<int>());
        };
        for (int j = 0; j < col; ++j) {
            int maxNum = 0;
            for (int i = 0; i < row; ++i) {
                maxNum = max(maxNum, nums[i][j]);
            };
            score += maxNum;
        };
        return score;
    };
};