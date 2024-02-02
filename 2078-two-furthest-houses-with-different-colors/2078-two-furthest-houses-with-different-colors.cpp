class Solution {
public:
    int maxDistance(vector<int>& col) {
        int ans = 0, n = col.size();
        for (int i = 0, j = n - 1; j >= 0; ++i, --j) {
            if (col[i] != col[n - 1]) ans = max(ans, n - i - 1);            
            if (col[j] != col[0]) ans = max(ans, j);            
        };
        return ans;
    };
};