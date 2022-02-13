class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        vector<int> nums;
        for (auto i = 0; i < m; i++)
            for (auto j = 0; j < n; j++)
                nums.push_back(grid[i][j]);
        
        sort(nums.begin(), nums.end());
        
        int average = nums[(m * n) / 2], operations = 0;
        for (auto i = 0; i < nums.size(); i++) {
            int diff = abs(nums[i] - average);
            if (diff % x) return -1;
            operations += (diff / x);
        };
        return operations;
    };
};