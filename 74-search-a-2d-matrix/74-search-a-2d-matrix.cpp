class Solution {
public: 
    bool binarySearch(vector<int> v, int low, int high, int key) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);        
        if (high >= low) {
            int mid = (low + high) / 2;
            return (
                key == v[mid]
                ? true 
                : (v[mid] > key) 
                   ? binarySearch(v, low, mid - 1, key) 
                   : binarySearch(v, mid + 1, high, key)
            );
        }
        return false;        
    }   

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);        
        if (target < matrix[0][0]) return false;
        int v;
        for (int i = 0; i < matrix.size(); i++) {
            v = i;
            if (target <= matrix[i][matrix[i].size() - 1]) break;
        };
        return binarySearch(matrix[v], 0, matrix[v].size() - 1, target);
    };
};