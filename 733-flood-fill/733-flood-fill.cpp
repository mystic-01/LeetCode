class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        set<pair<int, int>> visited;
        vector<pair<int, int>> offset = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        int rowSize = image.size(), colSize = image[0].size(), srcColor = image[sr][sc];
        while (!q.empty()) {
            int size = q.size();
            for (auto i = 0; i < size; i++) {
                int r = q.front().first, c = q.front().second;   
                q.pop();
                image[r][c] = color, visited.insert({r, c});
                for (auto &duo : offset) {
                    int row = r + duo.first, col = c + duo.second;
                    if (row > - 1 && row < rowSize && col > - 1 && col < colSize 
                        && image[row][col] == srcColor && !visited.count({row, col})) 
                        q.push({row, col});
                };
            };
        };
        return image;
    };
};