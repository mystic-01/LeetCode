class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& pairs) {
        int n = pairs.size() + 1, curr = 2147483647;
        map<int, pair<int, int>> m;
        vector<int> ans(n);
        for (auto &vec : pairs) {
            if (m.find(vec[0]) == m.end()) {
                m[vec[0]].first = vec[1];
                m[vec[0]].second = INT_MIN;
            } else {
                m[vec[0]].second = vec[1];
            };
            if (m.find(vec[1]) == m.end()) {
                m[vec[1]].first = vec[0];
                m[vec[1]].second = INT_MIN;
            } else {
                m[vec[1]].second = vec[0];
            };
        };
        for (auto &it : m) {
            if (it.second.second == INT_MIN) {
                curr = it.first;
                break;
            };
        };
        ans[0] = curr;
        for (int i = 1, parent = curr; i < n; ++i) {
            if (m[curr].first != parent) {
                parent = curr;
                curr = m[curr].first;
            } else {
                parent = curr;
                curr = m[curr].second;
            };
            ans[i] = curr;
        };
        return ans;
    };
};