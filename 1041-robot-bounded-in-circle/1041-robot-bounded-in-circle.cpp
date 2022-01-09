class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, i = 0;
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for (auto &s : instructions) {
            if (s == 'R') {
                i = (i + 1) % 4;
            } else if (s == 'L') {
                i = (i + 3) % 4;
            } else{ 
                x += dir[i][0];
                y += dir[i][1];
            };            
        };
        return (x == 0 && y == 0) || i > 0;
    };
};