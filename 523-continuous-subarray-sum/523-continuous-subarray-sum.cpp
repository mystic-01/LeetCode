class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        if (n < 2) return 0;
        vector<int> v;
        unordered_map<int, int> m;
        for (auto i : nums) {
            sum += i;
            v.push_back(sum % k);
            m[sum % k]++;
        };
        for (int i = 0; i < n; i++) {
            if ((v[i] == 0 && i != 0) || (v[i] == 0 && find(v.begin() + i + 1, v.end(), v[i]) != v.end())) return 1;
            if (i < n - 2 && m[v[i]] > 1 && find(v.begin() + i + 2, v.end(), v[i]) != v.end()) return 1;
        };
        return 0;
    };
};