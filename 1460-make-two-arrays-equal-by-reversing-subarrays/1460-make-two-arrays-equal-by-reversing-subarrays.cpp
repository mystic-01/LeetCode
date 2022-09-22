class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> m;
        for (auto &i : target) m[i]++;
        for (auto &j : arr) m[j]--;
        for (auto &k : m) if (k.second != 0) return false;
        return true;
    };
};