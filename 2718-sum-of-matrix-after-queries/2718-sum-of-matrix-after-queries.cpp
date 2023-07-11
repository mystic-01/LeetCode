class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& q) {
        bool row[n], col[n];
        int freeRowCount = n, freeColCount = n;
        
        for (auto i = 0; i < n; i++) row[i] = 0, col[i] = 0;
        
        long long ans = 0;
        int qSize = q.size();
        
        for (auto i = qSize - 1; i >= 0; i--) {
            bool isRow = q[i][0];
            int idx = q[i][1], wt = q[i][2], count = 0;
            
            if (isRow) {
                if (row[idx] == 0) count = freeColCount, freeRowCount--, row[idx] = wt;
            } else {
                if (col[idx] == 0) count = freeRowCount, freeColCount--, col[idx] = wt;
            };
            ans += (count * wt);
        }; 
        return ans;
    };
};


/*
Input: n = 3, q = [[0,0,1],[1,2,2],[0,2,3],[1,0,4]]

sum = 0

row [n] = {0, 0, 0}
col [n] = {0, 0, 0}

q:
1

sum += q[2] * n;
if (q[0] == 0) {
    
};


*/