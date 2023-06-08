class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        
        int row = grid.size(), col = grid[0].size(), i = row - 1, j = 0;
    
        
        while (i >= 0 && j < col) {
            if (grid[i][j] < 0) ans += (col - j), i--;
            else j++;
        };
        
        return ans;
    };
};

/*
[[ 4, 3, 2,-1]
,[ 3, 2, 1,-1]
,[ 0,-1,-1,-2]
,[-1,-1,-2,-3]]


0,3
3,0
*/