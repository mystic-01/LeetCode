class Solution {
private:
    int offset[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<int, int>> q;
    set<pair<int, int>> visited;

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int &sr, int &sc, int &color) {
        q.push({sr, sc});
        
        int rowSize = image.size(), colSize = image[0].size(), srcColor = image[sr][sc];
        while (!q.empty()) {
            int size = q.size();
            for (auto i = 0; i < size; i++) {
                int r = q.front().first, c = q.front().second;   
                q.pop();
                image[r][c] = color, visited.insert({r, c});
                for (auto &duo : offset) {
                    int row = r + duo[0], col = c + duo[1];
                    if (row > - 1 && row < rowSize && col > - 1 && col < colSize 
                        && image[row][col] != color && image[row][col] == srcColor && !visited.count({row, col})) 
                        q.push({row, col});
                };
            };
        };
        return image;
    };
};