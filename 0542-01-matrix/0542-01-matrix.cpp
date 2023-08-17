// From such a brute-ish solution to such a simple yet effective one!

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        int offsets[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        queue<pair<int, int>> q;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!mat[i][j]) {
                    q.push({i, j});
                    mat[i][j] = 0;
                } else mat[i][j] = INT_MAX;                
            };                
        };
        
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;    
            q.pop();
            for (int i = 0; i < 4; i++) {
                int a = x + offsets[i][0], b = y + offsets[i][1];                
                if (a >= 0 && a < row && b >= 0 && b < col && mat[x][y] + 1 < mat[a][b]) {
                    mat[a][b] = mat[x][y] + 1;
                    q.push({a, b});                    
                };
            };  
        };
        
        return mat;
    };
};