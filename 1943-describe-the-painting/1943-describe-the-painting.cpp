static const int maxSize = 1e5 + 1;
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<long long>> ans;
        long long line[maxSize];
        memset(line, 0, sizeof(line));
        bool isEnd[maxSize];
        memset(isEnd, 0, sizeof(isEnd));
            
        long long start = 0, end = 0, val = 0; 
        for (int i = 0; i < n; ++i) {
            start = nums[i][0], end = nums[i][1], val = nums[i][2];
            line[start] += val, line[end] -= val, isEnd[end] = true;
        };
        start = 1, end = 1, val = line[1];
        for (int i = 1; i < maxSize; ++i) {
            line[i] += line[i - 1];
            if (val > 0) {    
                if (line[i] == val) {
                    if (isEnd[i]) {
                        ans.push_back({start, i, val});                    
                        start = i, end = i, val = line[i];
                    };
                    end = i;                    
                } else {
                    ans.push_back({start, end + 1, val});
                    start = i, end = i, val = line[i];
                };
            } else {
                start = i, end = i, val = line[i];
            };
        };
        return ans;
    };
};

// 1  2  3  4  5  6  7  8  9  10
// 12       -12
//          12      -12
// 12 12 12 12 12 12 12  