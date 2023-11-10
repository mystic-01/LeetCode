class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& pairs) {
        int n = pairs.size() + 1, curr = 2147483647;
        map<int, vector<int>> m;
        vector<int> ans(n);
        for (auto &vec : pairs) {
            m[vec[0]].push_back(vec[1]);
            m[vec[1]].push_back(vec[0]);
        };
        for (auto &it : m) {
            if (it.second.size() == 1) {
                curr = it.first;
                break;
            };
        };
        ans[0] = curr;
        for (int i = 1, parent = curr; i < n; ++i) {
            for (auto &it2 : m[curr]) {
                if (it2 != parent) {
                    parent = curr;
                    curr = it2;
                    ans[i] = curr;
                    break;
                };
            };                
        };
        return ans;
    };
};