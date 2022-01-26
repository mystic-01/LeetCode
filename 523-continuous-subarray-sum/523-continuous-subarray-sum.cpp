class Solution {
public:
    bool checkSubarraySum(vector<int>& v, int k) {
        int n = v.size(), sum = 0;
        if (n < 2) return 0;
        unordered_map<int, int> m;
        for (auto &i : v) {
            sum += i;
            i = (sum % k);
            m[sum % k]++;
        };
        for (int i = 0; i < n; i++) {
            if ((v[i] == 0) && (i != 0)) return 1;
            if (i < n - 2 && m[v[i]] > 1 && find(v.begin() + i + 2, v.end(), v[i]) != v.end()) return 1;
        };
        return 0;
    };
};