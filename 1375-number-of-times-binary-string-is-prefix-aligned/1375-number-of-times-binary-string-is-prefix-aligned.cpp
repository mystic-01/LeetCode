class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n = flips.size(), minYet = 2147483647, maxYet = -1, count = 0;
        for (int i = 0; i < n; ++i) {
            minYet = min(minYet, flips[i]);
            maxYet = max(maxYet, flips[i]);
            if (minYet == 1 && maxYet == i + 1) {
                ++count;
            };
        };        
        return count;
    };
};