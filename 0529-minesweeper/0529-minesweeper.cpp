class Solution {
public:
    int countAdjacentMines(int x, int y, int &row, int &col, vector<vector<char>> &board) {
        int count = 0;
        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                if (di != 0 || dj != 0) {
                    int a = x + di, b = y + dj;
                    if (a >= 0 && a < row && b >= 0 && b < col) {
                        count += board[a][b] == 'M';    
                    };
                };
            };        
        };
        return count;
    };
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        char curr = board[x][y];
        
        if (curr == 'M') {
            board[x][y] = 'X';
        } else {
            int row = board.size(), col = board[0].size();
            int adjMines =  countAdjacentMines(x, y, row, col, board);
            if (adjMines) {
                board[x][y] = char('0' + adjMines);
            } else {
                board[x][y] = 'B';
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        if (di != 0 || dj != 0) {
                            int a = x + di, b = y + dj;
                            if (a >= 0 && a < row && b >= 0 && b < col && (board[a][b] == 'M' || board[a][b] == 'E')) {
                                vector<int> newClick = {a, b};
                                updateBoard(board, newClick);
                            };
                        };
                    };        
                };
            };                        
        };
        return board;
    };
};