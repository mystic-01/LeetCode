class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> v(1001, 0);
        for (auto &i : target) v[i]++;
        for (auto &j : arr) v[j]--;
        for (auto &k : v) if (k != 0) return false;
        return true;
    };
};