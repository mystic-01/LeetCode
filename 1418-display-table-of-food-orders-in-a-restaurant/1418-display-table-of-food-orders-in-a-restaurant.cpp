class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, map<string, int>> m;
        set<string> s;
        
        for (auto &order : orders) {
            m[stoi(order[1])][order[2]]++;
            s.insert(order[2]);
        };
        
        int row = m.size(), col = s.size();
        
        vector<vector<string>> ans(row + 1, vector<string>(col + 1));
        ans[0][0] = "Table";
        

        auto sIt = s.begin();
        for (auto j = 1; j < col + 1; j++, sIt++) {
            ans[0][j] = *sIt;                        
        };
                
        auto it = m.begin();
        for (auto i = 1; i < row + 1; i++, it++) {
            ans[i][0] = to_string(it->first);
            for (auto j = 1; j < col + 1; j++) {
                ans[i][j] = to_string(it->second[ans[0][j]]);
            };
        };
        
        return ans;
    };
};