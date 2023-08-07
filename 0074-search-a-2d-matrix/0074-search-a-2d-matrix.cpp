class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int rLo = 0, rHi = mat.size() - 1, cLo = 0, cHi = mat[0].size() - 1;         
    
        while (rLo <= rHi) {
            int rMid = (rHi - rLo) / 2 + rLo;             
        
            // If a row's last element is greater than target
            if (mat[rMid][cHi] > target) {
                // If even row's first element is greater than target, we reduce search space to row - 1;
                if (mat[rMid][0] > target) rHi = rMid - 1;
                // else element must be between this row's [0] and [last]; 
                else {
                    // Simple decisive binary search
                    while (cLo <= cHi) {
                        int cMid = (cHi - cLo) / 2 + cLo;             
                        if (mat[rMid][cMid] > target) cHi = cMid - 1;
                        else if (mat[rMid][cMid] < target) cLo = cMid + 1;
                        else return true;
                    };
                    return false;
                };
            // If row's last element is smaller than target, we reduce search space to row + 1 
            } else if (mat[rMid][cHi] < target) rLo = rMid + 1;
            // If row's last element is equal to target, happiest case!
            else return true;
        };
        return false;
    };
};