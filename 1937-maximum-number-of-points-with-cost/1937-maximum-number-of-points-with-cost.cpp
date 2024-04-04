class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int row = points.size(), col = points[0].size();
        long long curr[col], prev[col], left[col], right[col];     
        
        for (int j = col - 1; j >= 0; --j) {
            prev[j] = points[row - 1][j];
        }; 
        
        for (int i = row - 2; i >= 0; --i) {
            for (int j = col - 1; j >= 0; --j) {
                curr[j] = prev[j];
            };  
            
            left[0] = prev[0];
            for (int j = 1; j < col; ++j) {
                left[j] = max(curr[j], left[j - 1] - 1);
            }; 
            
            right[col - 1] = prev[col - 1];
            for (int j = col - 2; j >= 0; --j) {
                right[j] = max(curr[j], right[j + 1] - 1);
            };  
            
            for (int j = col - 1; j >= 0; --j) {
                curr[j] = points[i][j] + max(left[j], right[j]);
            };
            
            for (int j = col - 1; j >= 0; --j) {
                prev[j] = curr[j];
            };
        };
        return *max_element(prev, prev + col);
    };
};