class Solution {
public:
    int lowerBound(vector<vector<int>>& points, int target) {
        int low = 0, high = points.size() - 1;
        if (target <= points[low][0]) return low;
        if (target >= points[high][0]) return high;

        while (low < high) {
            int mid = (low + high) / 2;
            if (target <= points[mid][0]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        };
        return high;
    };
    
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        sort(points.begin(), points.end());
        vector<int> count(queries.size(), 0);
        int q = queries.size(), p = points.size();
        
        for (auto i = 0; i < q; i++) {
            int x = queries[i][0], y = queries[i][1], r = queries[i][2], index = lowerBound(points, x - r);
            for (auto j = index; j < p && points[j][0] <= x + r; j++)
                count[i] += pow(x - points[j][0], 2) + pow(y - points[j][1], 2) <= pow(r, 2);
        };
        return count;
    };
};