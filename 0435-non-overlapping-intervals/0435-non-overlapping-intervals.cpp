class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int merges = 0, currEnd = intervals[0][1];
        
        for (auto it = 1; it < intervals.size(); it++) {
            int start = intervals[it][0], end = intervals[it][1]; 
            if (start < currEnd) merges++, currEnd = min(currEnd, end);
            else currEnd = end;
        };
        
        return merges;
    };
};