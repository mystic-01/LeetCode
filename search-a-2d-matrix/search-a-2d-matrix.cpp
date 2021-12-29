class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (target < matrix[0][0]) return false;
        vector<int> v;
        for (int i = 0; i < matrix.size(); i++) {
            if (target <= matrix[i][matrix[i].size() - 1]) {
                v = matrix[i];
                break;
            };
        };  
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == target) return true;
        };
        return false;
    };
};