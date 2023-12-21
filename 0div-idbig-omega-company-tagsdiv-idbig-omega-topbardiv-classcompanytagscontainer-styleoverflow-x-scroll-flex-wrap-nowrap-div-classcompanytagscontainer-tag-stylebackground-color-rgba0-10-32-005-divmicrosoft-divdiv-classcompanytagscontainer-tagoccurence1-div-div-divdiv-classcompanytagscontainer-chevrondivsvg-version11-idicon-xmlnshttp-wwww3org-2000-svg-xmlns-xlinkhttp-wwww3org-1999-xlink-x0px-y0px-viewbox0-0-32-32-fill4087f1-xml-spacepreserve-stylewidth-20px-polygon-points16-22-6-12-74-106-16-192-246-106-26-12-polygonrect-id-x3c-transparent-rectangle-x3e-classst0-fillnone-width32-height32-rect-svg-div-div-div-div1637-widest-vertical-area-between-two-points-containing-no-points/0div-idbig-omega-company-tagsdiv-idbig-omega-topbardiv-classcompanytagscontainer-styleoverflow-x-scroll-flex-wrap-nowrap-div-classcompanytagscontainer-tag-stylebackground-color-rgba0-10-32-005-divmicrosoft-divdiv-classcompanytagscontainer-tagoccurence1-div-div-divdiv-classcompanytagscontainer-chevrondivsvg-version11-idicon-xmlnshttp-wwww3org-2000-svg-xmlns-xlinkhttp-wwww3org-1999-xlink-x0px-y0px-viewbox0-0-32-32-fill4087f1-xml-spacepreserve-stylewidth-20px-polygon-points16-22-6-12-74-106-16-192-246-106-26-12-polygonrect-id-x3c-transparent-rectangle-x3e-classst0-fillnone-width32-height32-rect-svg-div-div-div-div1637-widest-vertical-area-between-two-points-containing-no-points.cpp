class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int best = 0, prev = -1;
        for (auto &it : points) {
            if (prev != -1) best = max(best, it[0] - prev);
            prev = it[0];
        };
        return best;
    };
};