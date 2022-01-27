class Solution {
public:
    bool checkSubarraySum(vector<int>& v, int k) {
        int n = v.size(), sum = 0;
        if (n < 2) return 0;
        unordered_map<int, int> m;
        for (auto &i : v) {
            sum += i;
            i = (sum % k);
            m[i]++;
        };
        for (int i = 0; i < n; i++) {
            if (i > 0) m[v[i - 1]]--;
            
            if (v[i] == 0 && i > 0) return 1;
            if (i + 1 < n && v[i] != v[i+1] && m[v[i]] > 1) return 1;
            if (i + 1 < n && v[i] == v[i+1] && m[v[i]] > 2) return 1;
        };
        return 0;
    };
};