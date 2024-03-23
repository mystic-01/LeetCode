static const int outOfBounds = 1e9;

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = arr.size(), t = target.size();
        map<int, int> m;
        for (int i = 0; i < t; ++i) {
            m[target[i]] = i;
        };
        vector<int> lis;
        for (int i = 0; i < n; ++i) {
            if (m.find(arr[i]) != m.end()) {
                int idx = m[arr[i]];
                if (lis.empty() || idx > *lis.rbegin()) {
                    lis.push_back(idx);
                } else {
                    auto it = lower_bound(begin(lis), end(lis), idx);
                    lis[it - begin(lis)] = idx;
                };
            };

        };
        return t - lis.size();
    };
};