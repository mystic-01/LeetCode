class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        vector<vector<int>> ans, temp(group.size() + 1);
        
        for (int i = 0; i < group.size(); i++) {
            temp[group[i]].push_back(i);
            if (temp[group[i]].size() == group[i]) {
                ans.push_back({});
                swap(ans.back(), temp[group[i]]);
            };
        };
        
        return ans;
    };
};