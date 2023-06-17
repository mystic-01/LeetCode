class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& start) {
        int row = maze.size(), col = maze[0].size(), dist = 0;
        int offsets[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        queue<pair<int, int>> q;
        bool visited[row][col];
        
        for (auto i = 0; i < row; i++) {
            for (auto j = 0; j < col; j++) {
                visited[i][j] = 0;
            };
        };
        
        
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = 1;
        
        while (!q.empty()) {
            int size = q.size();    
            for (auto k = 0; k < size; k++) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                if (dist && (x == 0 || y == 0 || x == row - 1 || y == col - 1)) return dist;
            
                for (auto i = 0; i < 4; i++) {
                    int a = x + offsets[i][0], b = y + offsets[i][1];
                    if (a >= 0 && a < row && b >= 0 && b < col && !visited[a][b] && maze[a][b] == '.') {
                        q.push({a, b});
                        visited[a][b] = 1;
                    };
                };
            };
            dist++;
        };
        
        return -1;
    };
};