class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans = img;
        int row = img.size(), col = img[0].size(); 
        int offsets[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int sum = img[i][j], count = 1;
                for (int k = 0; k < 8; ++k) {
                    int x = i + offsets[k][0], y = j + offsets[k][1];
                    if (x >= 0 && x < row && y >= 0 && y < col) {
                        sum += img[x][y], ++count;                            
                    };    
                };
                ans[i][j] = sum / count;
            };            
        };
        return ans;
    };
};