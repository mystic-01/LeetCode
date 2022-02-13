class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size(), size = m * n;
        int nums[size];
        for (auto i = 0; i < m; i++)
            for (auto j = 0; j < n; j++)
                nums[(i * n) + j] = grid[i][j];
        
        sort(nums, nums + size);
        
        int average = nums[size / 2], operations = 0;
        for (auto i = 0; i < size; i++) {
            int diff = abs(nums[i] - average);
            if (diff % x) return -1;
            operations += (diff / x);
        };
        return operations;
    };
};