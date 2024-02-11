class Solution {
public:
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(), boomerangs = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> m;
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    int dist = pow(abs(points[i][0] - points[j][0]), 2) + pow(abs(points[i][1] - points[j][1]), 2);
                    boomerangs += ((++m[dist] - 1) * 2);
                };
            };        
        };
        return boomerangs;
    };
};