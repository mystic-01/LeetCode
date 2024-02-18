class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size(), l = 0, r = n - 1, lMax = 0, rMax = 0, ans = 0;
        while (l <= r) {
            if (heights[l] <= heights[r]) {
                if (heights[l] >= lMax) {
                    lMax = heights[l];
                } else {
                    ans += (lMax - heights[l]);    
                };
                ++l;
            } else {
                if (heights[r] >= rMax) {
                    rMax = heights[r];
                } else {
                    ans += (rMax - heights[r]);    
                };    
                --r;
            };    
        };
        return ans;
    };
};