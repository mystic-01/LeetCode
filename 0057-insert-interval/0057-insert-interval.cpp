class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& vec, vector<int>& newInterval) {
        int n = vec.size(), start = newInterval[0], end = newInterval[1], startIdx = INT_MIN, endIdx = INT_MIN;
        
        if (n && end < vec[0][0]) {
            vec.insert(vec.begin(), newInterval);
            return vec;
        } else if (n && start > vec[n - 1][1]) {
            vec.push_back(newInterval);
            return vec;
        };
        
        for (int i = 0; i < vec.size(); i++) {
            if (startIdx == INT_MIN) {
                if (start < vec[i][0]) {
                    vec.insert(vec.begin() + i, {start, 0});
                    startIdx = i;                                     
                } else if (start <= vec[i][1]) startIdx = i;                    
            };
            if (endIdx == INT_MIN) {
                if (end < vec[i][0]) {
                    endIdx = i - 1;      
                    vec[startIdx][1] = end;
                    break;
                } else if (end <= vec[i][1]) {
                    endIdx = i;   
                    vec[startIdx][1] = max(end, vec[endIdx][1]);
                    break;
                };
            };
        };
        
        if (startIdx == INT_MIN) {
            vec.push_back(newInterval);
        } else if (endIdx == INT_MIN) {
            vec[startIdx][1] = end;
            vec.erase(vec.begin() + startIdx + 1, vec.end());
        } else {
            vec.erase(vec.begin() + startIdx + 1, vec.begin() + endIdx + 1);            
        };
        
        return vec;
    };
};