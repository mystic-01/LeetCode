class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
//         queue<pair<int, int>>;
//         q.push({sx, sy});
//         int offsets[8][2] = {{0, 1}. {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        
//         while (!q.empty() && t--) {
//             int size = q.size();
//             for (int i = 0; i < size; i++) {
//                 int x = q.front().first, y = q.front().second;    
//                 q.pop();
//                 if (x == fx && y == fy) return true;
//                 for (int j = 0; j < 8; j++) {
//                     int a = x + offsets[j][0], b = y + offsets[j][1];    
//                     q.push({sx, sy});
//                 };
//             };
//         };
        
        int down = abs(sx - fx), right = abs(sy - fy), minSteps = max(down, right);
        if (sx == fx && sy == fy) return t != 1;    
        return minSteps <= t;
    };
};