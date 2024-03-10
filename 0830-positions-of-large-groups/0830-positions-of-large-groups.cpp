class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.size(), start = 0, end = 0;
        vector<vector<int>> ans;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                end = i;
            } else {
                if (end - start + 1 >= 3) {
                    ans.push_back({start, end});    
                };
                start = i, end = i;                
            };
        };
        if (end - start + 1 >= 3) {
            ans.push_back({start, end});    
        };        
        return ans;
    };
};