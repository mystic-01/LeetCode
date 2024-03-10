class Solution {
public:
    int offsets[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool isBoundaryElement(int &i, int &j, int &row, int &col) {
        return i == 0 || i == row - 1 || j == 0 || j == col - 1;        
    };
    
    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    bool isQueueTainted = false;
                    queue<pair<int, int>> q;        
                    set<pair<int, int>> s;        
                    q.push({i, j});
                    visited[i][j] = true;
                    
                    while (!q.empty()) {
                        int x = q.front().first, y = q.front().second;
                        isQueueTainted = isQueueTainted || isBoundaryElement(x, y, row, col);
                        q.pop();
                        if (!isQueueTainted) {
                            s.insert({x, y});
                        };
                        for (int k = 0; k < 4; ++k) {
                            int a = x + offsets[k][0], b = y + offsets[k][1];
                            if (a >= 0 && a < row && b >= 0 && b < col && board[a][b] == 'O' && !visited[a][b]) {      
                                q.push({a, b});
                                visited[a][b] = true;
                            };
                        };        
                    };
                    if (!isQueueTainted) {
                        for (auto &p : s) {
                            board[p.first][p.second] = 'X';    
                        };
                    };                    
                };
            };        
        };
    };
};