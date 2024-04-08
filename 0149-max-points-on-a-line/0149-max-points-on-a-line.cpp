class Solution {
public:
    double getSlope(vector<int> &p1, vector<int> &p2) {
        if (p1[0] - p2[0] == 0) {
            return INT_MAX;            
        };
        return (p1[1] - p2[1]) / (double)(p1[0] - p2[0]);                                
    };
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), maxPoints = 0;
        for (int i = 0, curr = 0; i < n; ++i, curr = 0) {
            unordered_map<double, int> m;
            for (int j = 0; j < n; ++j) {
                if (j == i) {
                    continue;
                };
                double slope = getSlope(points[j], points[i]);
                curr = max(curr, ++m[slope]);    
            };  
            maxPoints = max(maxPoints, curr + 1);
        };
        return maxPoints;
    };
};