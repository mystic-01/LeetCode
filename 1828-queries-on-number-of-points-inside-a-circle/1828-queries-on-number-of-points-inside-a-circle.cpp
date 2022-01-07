class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> count(queries.size(), 0);
        int q = queries.size(), p = points.size(); 
        for (auto i = 0; i < q; i++) {
            for (auto j = 0; j < p; j++) {
                if (pow(queries[i][0] - points[j][0], 2) + pow(queries[i][1] - points[j][1], 2) 
                    <= pow(queries[i][2], 2)) count[i]++;
            };
        };
        return count;
    };
};