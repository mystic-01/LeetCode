class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), currEnd = intervals[0][1], merges = 0;
        
        for (auto i = 1; i < n; i++) {
            int start = intervals[i][0], end = intervals[i][1];
            if (start < currEnd) merges++, currEnd = min(end, currEnd);
            else currEnd = end;
        };
        
        return merges;
    };
};