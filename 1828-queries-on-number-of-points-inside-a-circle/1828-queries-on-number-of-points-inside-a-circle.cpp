class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> count(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0], y = queries[i][1], r = queries[i][2]; 
            for (int j = 0; j < points.size(); j++) {
                int a = pow(x - points[j][0], 2), b = pow(y - points[j][1], 2); 
                if (a + b  <= r * r) count[i]++;
            };
        };
        return count;
    };
};