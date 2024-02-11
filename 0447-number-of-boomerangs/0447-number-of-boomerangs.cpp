class Solution {
public:
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(), boomerangs = 0;
        for (int i = 0; i < n; ++i) {
            map<int, int> m;
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    int dist = pow(abs(points[i][0] - points[j][0]), 2) + pow(abs(points[i][1] - points[j][1]), 2);
                    if (++m[dist] >= 2) {
                        boomerangs += ((m[dist] - 1) * 2);
                    }; 
                };
            };        
        };
        return boomerangs;
    };
};
                    // 1 -> (1!/2! * -1!) * 2
                    // 2 -> (1,2) (2,1) = 1 * 2 = (2!/2! * 0!) * 2
                    // 3 -> (1,2) (1,3) (2,1) (2,3) (3,1) (3,2) = 3 * 2 = (3!/2! * 1!) * 2
                    // 4 -> (1,2) (1,3) (1,4) (2,1) (2,3) (2,4) (3,1) (3,2) (3,4) (4,1) (4,2) (4,3) = 6 * 2 = (4!/2! * 2!) * 2
// 3C2 = 3, 4C2 = 6, 5C2 = 10, 6C2 = 15, 7C2 = 
// 0 2 4  6  6  4  2 0
// 0 2 6 12 18 22 24