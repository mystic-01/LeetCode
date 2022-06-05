class Solution {
public:
    int recurseNQueens(int col, int n, 
    unordered_map<int, int> mRow, unordered_map<int, int>  mUpperDiagonal, unordered_map<int, int> mLowerDiagonal) {
        if (col == n) return 1;
        int count = 0;
        
        for (auto row = 0; row < n; row++) {
            if (!mRow[row] && !mUpperDiagonal[col - row] && !mLowerDiagonal[col + row]) {
                mRow[row] = mUpperDiagonal[col - row] = mLowerDiagonal[col + row] = 1;
                
                count += recurseNQueens(col + 1, n, mRow, mUpperDiagonal, mLowerDiagonal);  
                
                mRow[row] = mUpperDiagonal[col - row] = mLowerDiagonal[col + row] = 0;
            };            
        };
        return count;
    };

    
    int totalNQueens(int n) {
        unordered_map<int, int> mRow, mUpperDiagonal, mLowerDiagonal;
        return recurseNQueens(0, n, mRow, mUpperDiagonal, mLowerDiagonal);
    };
};