class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        vector<vector<int>> ans;
        map<int, int> m;
        
        for (int i = 0; i < group.size(); i++) {
            if (m.find(group[i]) == m.end()) {
                ans.push_back({i});
                m[group[i]] = ans.size() - 1;
            } else {
                if (ans[m[group[i]]].size() < group[i]) {
                    ans[m[group[i]]].push_back(i);
                } else {
                    ans.push_back({i});
                    m[group[i]] = ans.size() - 1;
                };
            };                
        };
        
        return ans;
    };
};