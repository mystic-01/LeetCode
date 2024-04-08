class Solution {
public:
    double getSlope(vector<int> &p1, vector<int> &p2) {
        if (p1[0] - p2[0] == 0) {
            return INT_MAX;            
        };
        return (p1[1] - p2[1]) / (double)(p1[0] - p2[0]);                                
    };
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), maxPoints = n == 1 ? 1 : 2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == i) {
                    continue;
                };
                double slope = getSlope(points[j], points[i]);
                int curr = 2;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) {
                        continue;
                    };
                    double currSlope = getSlope(points[k], points[i]);
                    curr += (currSlope == slope);
                    maxPoints = max(maxPoints, curr);
                    // cout << i << "i " << j << "j " << k << "k  : " << slope << " " << currSlope << " " << curr << " " << maxPoints << "\n";   
                };
            };        
        };
        // cout << "\n";
        return maxPoints;
    };
};