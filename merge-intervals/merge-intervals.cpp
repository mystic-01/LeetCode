class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> pair = intervals[0];
        auto n = intervals.size();
        for (auto i = 0; i < n; i++) {
            if (pair[1] >= intervals[i][0]) {
                pair[1] = max(pair[1], intervals[i][1]);
            } else {
                ans.push_back(pair);
                pair = intervals[i];
            }
        };
        ans.push_back(pair);
        return ans;
    };
};