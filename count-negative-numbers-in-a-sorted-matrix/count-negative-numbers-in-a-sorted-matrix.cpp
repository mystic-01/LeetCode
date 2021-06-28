class Solution {
public:

    
    int countNegatives(vector<vector<int>>& grid) {
          int negatives = 0;
          for (int i = 0; i < grid.size(); i++) {
              // binarySearch(grid[i], 0, grid[i].size());
              for (int j = 0; j < grid[i].size(); j++) {
                  if (grid[i][j] < 0) {
                      negatives += grid[i].size() - j;
                      break;
                  };
              };
          };
        return negatives;
    };
};