class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<string> grid(3, string(3, ' '));
        int i = 0;
        for (auto &vec : moves) {
            grid[vec[0]][vec[1]] = i % 2 ? 'B' : 'A', ++i;
        };
        
        for (int i = 0; i < 3; ++i) {
            if (grid[0][i] != ' ' && grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i]) {
                return string(1, grid[0][i]);
            };
            if (grid[i][0] != ' ' && grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2]) {
                return string(1, grid[i][0]);
            };
        };
        if (grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) {
            return string(1, grid[0][0]);
        };
        if (grid[0][2] != ' ' && grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0]) {
            return string(1, grid[0][2]);
        };
        return moves.size() == 9 ? "Draw" : "Pending";
    };
};