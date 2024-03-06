class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> line(n + 1);
        for (auto &vec : bookings) {
            line[vec[0] - 1] += vec[2];            
            line[vec[1]] -= vec[2];            
        };
        for (int i = 1; i < n; ++i) {
            line[i] += line[i - 1];
        };
        line.pop_back();
        return line;
    };
};